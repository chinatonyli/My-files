#include <stdio.h>
#include <stdlib.h>
#include <SPI.h>

extern "C" {
    #include "ssd1306.cpp"
}

#define NBYTES ((128 * 64) / 8)
#define FRAMES(length) ((length) / (NBYTES))

#define DC 9
#define RST 8
#define BUFFER_SIZE 1024 + 512
#define RESET_WHEN_BUFFER_FULL(var) var = (var - BUFFER_SIZE == 0) ? 0 : var



unsigned char buf[BUFFER_SIZE];
unsigned char ebufp;
unsigned char sbufp;
unsigned char i = 0;
unsigned char j = 0;


void setup(void)
{
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);
    SPI.setClockDivider(SPI_CLOCK_DIV64);

    ssd1306_init(DC, RST);
    Serial.begin(115200);
    Serial.println("X");
}


void loop(void)
{

    while (Serial.available() && !(ebufp - sbufp >= BUFFER_SIZE - 1 || (ebufp + (BUFFER_SIZE - sbufp) >= BUFFER_SIZE - 1 && ebufp < sbufp))) {
        buf[ebufp] = Serial.read();
        if (buf[ebufp] == -1) {
            continue;
        }
        ebufp++;
        RESET_WHEN_BUFFER_FULL(ebufp);
    }

    if ((ebufp - sbufp >= 3) || ((ebufp + (BUFFER_SIZE - sbufp) >= 3 && ebufp < sbufp))) {
        i = buf[sbufp++];
        RESET_WHEN_BUFFER_FULL(sbufp);

        if (i >= 8) {
            return;
        }

        j = buf[sbufp++];
        RESET_WHEN_BUFFER_FULL(sbufp);

        ssd1306_set_coordinate(j, i);
        ssd1306_data(~buf[sbufp++]);  // flip black and white for the screen

        RESET_WHEN_BUFFER_FULL(sbufp);

    }
}
