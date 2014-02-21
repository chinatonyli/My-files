#ifndef __DS1307__
#define __DS1307__

typedef struct DateTime
{
    unsigned char second;
    unsigned char minute;
    unsigned char hour;
    unsigned char weekday;
    unsigned char monthday;
    unsigned char month;
    unsigned char year;
} DateTime;


void ds1307_init(unsigned char address);
inline unsigned char bcd2dec(unsigned char val);
DateTime *ds1307_get(void);

#endif
