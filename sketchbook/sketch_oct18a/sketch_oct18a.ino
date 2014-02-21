#include "Arduino.h"

int chr;
int led_pin = 13;
char message[81] = {0};


void setup()
{
    Serial.begin(9600);
    pinMode(led_pin, OUTPUT);
    Serial.println("Welcome to Arduino!");
}


void loop()
{
    chr = Serial.read();

    if (chr == EOF) {
        // Give up the CPU time
        return;
    }

    if (chr == 'R') {
        strcpy(message, "Hello, world!\r\n");
    }
    else if (chr == 'K') {
        strcpy(message, "Hello, kitty!\r\n");
    }
    else if (chr == 'N') {
        strcpy(message, "Good night!\r\n");
    }
    else {
        message[0] = chr;
        strcpy(&message[1], ": I don't know!\r\n");
    }
    digitalWrite(led_pin, HIGH);
    delay(500);
    digitalWrite(led_pin, LOW);
    delay(500);
    Serial.print(message);
    strcpy(message, "");
}
