#include <dht.h>

#include <SPI.h>
#include <ssd1306.h>

#include <Wire.h>
#include <ds1307.h>

#include <LowPower.h>

#define DHT11_PIN 4
#define DS1307_ADDRESS 0x68

#define EPOCH 2000
#define MAX_RETRY 3


dht DHT;
bool last_rtc_status = true;


void setup(void)
{
    Serial.begin(9600);
    Serial.println("DHT TEST PROGRAM ");
    Serial.print("LIBRARY VERSION: ");
    Serial.println(DHT_LIB_VERSION);
    Serial.println("System Started.");

    Wire.begin();
    ds1307_init(DS1307_ADDRESS);

    pinMode(10, OUTPUT);
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);
    SPI.setClockDivider(SPI_CLOCK_DIV128);
    ssd1306_init(9, 8);

    static const char temperature_text[] = "Temperature: ";
    ssd1306_draw_8x16_string(0, 0, temperature_text);

    static char humidity_text[] = "Humidity: ";
    ssd1306_draw_8x16_string(0, 2, humidity_text);
}


void loop()
{
    switch (DHT.read11(DHT11_PIN))
    {
        case 0:  break;
        case -1: Serial.println("Checksum error"); return;
        case -2: Serial.println("Time out error"); return;
        default: Serial.println("Unknown error"); return;
    }

    char temperature_value[3];
    sprintf(temperature_value, "%-2dC", (int) DHT.temperature);
    ssd1306_draw_8x16_string(104, 0, temperature_value);

    char humidity_value[4];
    if ((int) DHT.humidity == 100) {
        sprintf(humidity_value, "%-3d%%", (int) DHT.humidity);
    }
    else {
        sprintf(humidity_value, "%-2d%%", (int) DHT.humidity);
        ssd1306_draw_8x16_string(80, 2, humidity_value);
    }

    int i = 0;
    DateTime *dt = NULL;
    for (i = 0; i < MAX_RETRY; i++) {
        dt = ds1307_get();
        if (dt != NULL) {
            break;
        }
        delay(100);
        i++;
    }
    if (dt != NULL) {
        if (!last_rtc_status) {
            // If is is broken before, but ok now
            ssd1306_clear_row(5);
            ssd1306_clear_row(6);
        }
        last_rtc_status = true;
        char date[18];
        sprintf(date, "%04d/%02d/%02d", EPOCH + dt->year, dt->month, dt->monthday);
        ssd1306_draw_8x16_string(25, 4, date);
        
        char time[18];
        sprintf(time, "%02d:%02d:%02d", dt->hour, dt->minute, dt->second);
        ssd1306_draw_8x16_string(35, 6, time);

        free(dt);
    }
    else {
        if (last_rtc_status) {
            // If it is ok before, but broken now
            ssd1306_clear_row(4);
            ssd1306_clear_row(5);
            ssd1306_clear_row(6);
            ssd1306_clear_row(7);
        }
        last_rtc_status = false;
        static const char check[] = "Check the RTC.";
        ssd1306_draw_8x16_string(10, 5, check);
    }

    LowPower.powerExtStandby(SLEEP_1S, ADC_OFF, BOD_OFF, TIMER2_OFF);
}
