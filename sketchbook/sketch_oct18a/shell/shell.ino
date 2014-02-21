#include "Arduino.h"

int i = 0;
char chr[2];
int led_pin = 13;
char message[81] = {0};


void setup()
{
    Serial.begin(9600);
    pinMode(led_pin, OUTPUT);
    Serial.print("\033[2J");
    Serial.println("Welcome to Arduino!");
    Serial.print("# ");
}


void loop()
{
    chr[0] = Serial.read();
    chr[1] = '\0';

    if (chr[0] == EOF) {
        return;
    }

    else if (chr[0] == '\n' || chr[0] == '\r') {
        message[i] = '\0';
        i = 0;
        Serial.print("\r\n");

        if (strcmp(message, "uname") == 0) {
            Serial.println("GaiziShell");
        }
        else if (strcmp(message, "whoami") == 0) {
            Serial.println("root");
        }
        else if (strcmp(message, "clear") == 0) {
            Serial.print("\033[2J");
        }
        else if (strcmp(message, "") == 0) {
            // do nothing
        }
        else {
            Serial.print("gsh: command not found: ");
            Serial.println(message);
        }

        Serial.print("# ");
        return;
    }

    message[i] = chr[0];

    Serial.print(chr);
    i++;
}
