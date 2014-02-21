#include <Arduino.h>
#include <SPI.h>
#include "ssd1306.h"
#include "codetab.h"

#define HEIGHT 64
#define WIDTH 128
#define SEGMENTS 8


unsigned char _dc;
unsigned char _rst;


void ssd1306_data(unsigned char data)
{
    digitalWrite(_dc, HIGH);
    SPI.transfer(data);
}


void ssd1306_command(unsigned char command)
{
    digitalWrite(_dc, LOW);
    SPI.transfer(command);
}


void ssd1306_set_coordinate(unsigned char x, unsigned char y)
{
    ssd1306_command(0xB0 + y);
    ssd1306_command(((x & 0xF0) >> 4) | 0x10);
    ssd1306_command((x & 0x0F) | 0x01);
}


void ssd1306_fill(unsigned char color)
{
    unsigned char x;
    unsigned char y;

    for (y = 0; y < SEGMENTS; y++) {
        ssd1306_command(0xB0 + y);
        ssd1306_command(0x01);
        ssd1306_command(0x10);

        for (x = 0; x < WIDTH; x++) {
            ssd1306_data(color);
        }
    }
}


void ssd1306_clear(void)
{
    ssd1306_fill(0x00);
}


void ssd1306_clear_row(unsigned char row)
{
    unsigned char x;
    unsigned char y;

    ssd1306_command(0xB0 + row);
    ssd1306_command(0x01);
    ssd1306_command(0x10);

    for (x = 0; x < WIDTH; x++) {
        ssd1306_data(0x00);
    }
}


void ssd1306_clear_row_column(unsigned char row, unsigned char column_start, unsigned char column_end)
{
    unsigned char x;
    unsigned char y;

    ssd1306_command(0xB0 + row);
    ssd1306_command(0x01);
    ssd1306_command(0x10);

    for (x = column_start; x < column_end; x++) {
        ssd1306_data(0x00);
    }
}


void ssd1306_init(const unsigned char dc, const unsigned char rst)
{
    _dc = dc;
    _rst = rst;

    pinMode(_dc, OUTPUT);
    pinMode(_rst, OUTPUT);

    digitalWrite(_rst, LOW);
    delay(100);
    digitalWrite(_rst, HIGH);

    ssd1306_command(0xAE); // turn off the screen

    ssd1306_command(0xD5); // set display clock divide ratio/oscillator frequency
    ssd1306_command(0x80); // suggested ratio: 0x80

    ssd1306_command(0xA8); // set multiplex
    ssd1306_command(0x3F); // height: 64

    ssd1306_command(0xD3); // set display offset
    ssd1306_command(0x00); // offset: 0

    ssd1306_command(0x40 | 0x0); // set start line

    ssd1306_command(0x8D); // set charge pump
    ssd1306_command(0x14); // charge pump: disable

    ssd1306_command(0x20); // set memory mode
    ssd1306_command(0x00); // mode: 0

    ssd1306_command(0xA0 | 0x1); // set seg/column mapping

    ssd1306_command(0xC8); // set com/row scan direction

    ssd1306_command(0xDA); // set com pins hardware configuration
    ssd1306_command(0x12); // compins: 0x12

    ssd1306_command(0x81); // set contrast control register
    ssd1306_command(0xCF); // brightness: 0xCF

    ssd1306_command(0xD9); // set pre-charge period
    ssd1306_command(0xF1); // pre-charge: 15 clocks / discharge: 1 clock

    ssd1306_command(0XDB); // set vcom detect
    ssd1306_command(0x40); // vcom deselect level: 0x40

    ssd1306_command(0xA4); // disable entire display

    ssd1306_command(0xA6); // disable inverse display (normal display)

    ssd1306_command(0xAF); // turn on the screen

    ssd1306_clear();
    ssd1306_set_coordinate(0, 0);
}


void ssd1306_draw_6x8_string(unsigned char x, unsigned char y, const char *string)
{
    unsigned char i;
    const char *chr;
    char printable_char;

    for (chr = string; *chr != '\0'; chr++) {
        printable_char = *chr - ' ';
        if (x > 126) {
            x = 0;
            y++;
        }
        ssd1306_set_coordinate(x, y);
        for (i = 0; i < 6; i++) {
            ssd1306_data(pgm_read_byte(&F6x8[printable_char][i]));
        }
        x += 6;
    }
}


void ssd1306_draw_8x16_string(unsigned char x, unsigned char y, const char *string)
{
    unsigned char i;
    const char *chr;
    char printable_char;
    for (chr = string; *chr != '\0'; chr++) {
        printable_char = *chr - ' ';
        if (x > 120) {
            x = 0;
            y++;
        }
        ssd1306_set_coordinate(x, y);
        for (i = 0; i < SEGMENTS; i++) {
            ssd1306_data(pgm_read_byte(&F8X16[printable_char * 16 + i]));
        }

        ssd1306_set_coordinate(x, y + 1);
        for (i = 0; i < SEGMENTS; i++) {
            ssd1306_data(pgm_read_byte(&F8X16[printable_char * 16 + i + 8]));
        }

        x += 8;
    }
}
