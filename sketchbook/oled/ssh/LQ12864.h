#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <Arduino.h>
#include <SPI.h>
#include "codetab.h"

#define HEIGHT 64
#define WIDTH 128

#define X_WIDTH 128
#define Y_WIDTH 64

#define DC 8
#define RST 12


void lcd_data_send(unsigned char data)
{
    digitalWrite(DC, HIGH);
    SPI.transfer(data);
}


void lcd_command_send(unsigned char command)
{
    digitalWrite(DC, LOW);
    SPI.transfer(command);
}


void lcd_set_position(unsigned char x, unsigned char y)
{
    lcd_command_send(0xb0+y);
    lcd_command_send(((x&0xf0)>>4)|0x10);
    lcd_command_send((x&0x0f)|0x01);
}


/*********************lcd全屏************************************/
void lcd_fill(unsigned char bmp_dat)
{
    unsigned char x, y;
    for (y = 0; y < 8; y++) {
        lcd_command_send(0xb0 + y);
        lcd_command_send(0x01);
        lcd_command_send(0x10);
        for (x = 0; x < X_WIDTH; x++) {
            lcd_data_send(bmp_dat);
        }
    }
}


/*********************lcd复位************************************/
void lcd_clear(void)
{
    lcd_fill(0x00);
}


/*********************lcd初始化************************************/
void lcd_init(void)
{
    pinMode(DC, OUTPUT);
    pinMode(RST, OUTPUT);

    delay(1);

    // Reset
    digitalWrite(RST, LOW);
    delay(100);
    digitalWrite(RST, HIGH);

    lcd_command_send(0xAE); // turn off the screen

    lcd_command_send(0xD5); // set display clock divide ratio/oscillator frequency
    lcd_command_send(0x80); // suggested ratio: 0x80

    lcd_command_send(0xA8); // set multiplex
    lcd_command_send(0x3F); // height: 64

    lcd_command_send(0xD3); // set display offset
    lcd_command_send(0x00); // offset: 0

    lcd_command_send(0x40 | 0x0); // set start line

    lcd_command_send(0x8D); // set charge pump
    lcd_command_send(0x14); // charge pump: disable

    lcd_command_send(0x20); // set memory mode
    lcd_command_send(0x00); // mode: 0

    lcd_command_send(0xA0 | 0x1); // set seg/column mapping

    lcd_command_send(0xC8); // set com/row scan direction

    lcd_command_send(0xDA); // set com pins hardware configuration
    lcd_command_send(0x12); // compins: 0x12

    lcd_command_send(0x81); // set contrast control register
    lcd_command_send(0xCF); // brightness: 0xCF

    lcd_command_send(0xD9); // set pre-charge period
    lcd_command_send(0xF1); // pre-charge: 15 clocks / discharge: 1 clock

    lcd_command_send(0XDB); // set vcom detect
    lcd_command_send(0x40); // vcom deselect level: 0x40

    lcd_command_send(0xA4); // disable entire display

    lcd_command_send(0xA6); // disable inverse display (normal display)

    lcd_command_send(0xAF); // turn on the screen

    lcd_clear();
    lcd_set_position(0, 0);
}


/***************功能描述：显示6*8一组标准ASCII字符串	显示的坐标（x,y），y为页范围0～7****************/
void lcd_P6x8Str(unsigned char x, unsigned char y, char *ch)
{
    unsigned int c=0,i=0,j=0;
    while (ch[j]!='\0')
    {
        c =ch[j]-32;
        if(x>126){x=0;y++;}
        lcd_set_position(x,y);
        for(i=0;i<6;i++)
            lcd_data_send(F6x8[c][i]);
        x+=6;
        j++;
    }
}


/*******************功能描述：显示8*16一组标准ASCII字符串	 显示的坐标（x,y），y为页范围0～7****************/
void lcd_P8x16Str(unsigned char x, unsigned char y, char *ch)
{
    unsigned char c = 0, i = 0, j = 0;
    while (ch[j] != '\0')
    {
        c = ch[j]-32;
        if (x > 120) {
            x = 0;
            y++;
        }
        lcd_set_position(x, y);
        for (i = 0; i < 8; i++) {
            lcd_data_send(F8X16[c * 16 + i]);
        }
        lcd_set_position(x, y + 1);
        for (i = 0; i < 8; i++) {
            lcd_data_send(F8X16[c * 16 + i + 8]);
        }
        x += 8;
        j++;
    }
}


/*****************功能描述：显示16*16点阵  显示的坐标（x,y），y为页范围0～7****************************/
void lcd_P16x16Ch(unsigned char x, unsigned char y, unsigned char N)
{
    unsigned char wm=0;
    unsigned int adder=32*N;  //
    lcd_set_position(x, y);
    for(wm = 0;wm < 16;wm++)  //
    {
        lcd_data_send(F16x16[adder]);
        adder += 1;
    }
    lcd_set_position(x, y + 1);
    for(wm = 0;wm < 16;wm++) //
    {
        lcd_data_send(F16x16[adder]);
        adder += 1;
    }
}


/***********功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7*****************/
void lcd_draw_bmp(int x0, int y0, int x1, int y1, const unsigned char BMP[])
{
    unsigned int j=0;
    unsigned int x,y;

    if(y1%8==0) y=y1/8;
    else y=y1/8+1;
    for(y=y0;y<y1;y++)
    {
        lcd_set_position(x0,y);
        for(x=x0;x<x1;x++)
        {
            lcd_data_send(BMP[j++]);
        }
    }
}
