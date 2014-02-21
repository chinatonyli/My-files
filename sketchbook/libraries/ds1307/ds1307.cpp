#include <Arduino.h>
#include <Wire.h>
#include <stdbool.h>
#include "ds1307.h"


unsigned char _ds1307_address;


void ds1307_init(unsigned char address)
{
    _ds1307_address = address;
}


inline unsigned char bcd2dec(unsigned char value)
{
    return (value / 16 * 10) + (value % 16);
}


inline unsigned char dec2bcd(unsigned char value)
{
    return (value / 10 * 16) + (value % 10);
}


DateTime *ds1307_get(void)
{
    Wire.beginTransmission(_ds1307_address);
    Wire.write((byte) 0x00);
    Wire.endTransmission();
    Wire.requestFrom(_ds1307_address, 7);

    DateTime *date = (DateTime *) malloc(sizeof(DateTime));

    date->second = bcd2dec(Wire.read());
    date->minute = bcd2dec(Wire.read());
    date->hour = bcd2dec(Wire.read() & 0b111111);  // 24 hour time
    date->weekday = bcd2dec(Wire.read());  // 0-6 -> sunday - Saturday
    date->monthday = bcd2dec(Wire.read());
    date->month = bcd2dec(Wire.read());
    date->year = bcd2dec(Wire.read());

    if (date->second <= 59 && date->minute <= 59 &&
        date->hour <= 23 && date->month <= 12 && date->year < 100) {
        return date;
    }
    else {
        free(date);
        return NULL;
    }
}


void ds1307_set(DateTime *dt)
{
    Wire.beginTransmission(_ds1307_address);
    Wire.write((byte) 0x00);
    Wire.write(dec2bcd(dt->second));
    Wire.write(dec2bcd(dt->minute));
    Wire.write(dec2bcd(dt->hour));
    Wire.write(dec2bcd(dt->weekday));
    Wire.write(dec2bcd(dt->monthday));
    Wire.write(dec2bcd(dt->month));
    Wire.write(dec2bcd(dt->year));
    Wire.endTransmission();
}
