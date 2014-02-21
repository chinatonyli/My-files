#include <SPI.h>
#include "ssd1306.h"


void setup(void)
{
    pinMode(10, OUTPUT);
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);
    SPI.setClockDivider(SPI_CLOCK_DIV64);

    ssd1306_init(8, 12);
    ssd1306_clear();
    ssd1306_set_coordinate(0, 0);
    ssd1306_draw_8x16_string(0, 0, "hello, world!");
}


void loop(void)
{
}
