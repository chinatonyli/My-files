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


/*********************LCD写数据************************************/
void LCD_WrDat(unsigned char dat)
{
  digitalWrite(DC, HIGH);
  SPI.transfer(dat);
}


/*********************LCD写命令************************************/
void LCD_WrCmd(unsigned char cmd)
{
  digitalWrite(DC, LOW);
  SPI.transfer(cmd);
}


/*********************LCD 设置坐标************************************/
void LCD_Set_Pos(unsigned char x, unsigned char y)
{
  LCD_WrCmd(0xb0+y);
  LCD_WrCmd(((x&0xf0)>>4)|0x10);
  LCD_WrCmd((x&0x0f)|0x01);
}


/*********************LCD全屏************************************/
void LCD_Fill(unsigned char bmp_dat)
{
  unsigned char y,x;
  for(y=0;y<8;y++)
  {
    LCD_WrCmd(0xb0+y);
    LCD_WrCmd(0x01);
    LCD_WrCmd(0x10);
    for(x=0;x<X_WIDTH;x++)
      LCD_WrDat(bmp_dat);
  }
}


/*********************LCD复位************************************/
void LCD_CLS(void)
{
    LCD_Fill(0x00);
}


/*********************LCD初始化************************************/
void LCD_Init(void)
{
  pinMode(DC, OUTPUT);
  pinMode(RST, OUTPUT);

  // Reset
  digitalWrite(RST, LOW);
  delay(100);
  digitalWrite(RST, HIGH);

  LCD_WrCmd(0xae);//--turn off oled panel
  LCD_WrCmd(0x00);//---set low column address
  LCD_WrCmd(0x10);//---set high column address
  LCD_WrCmd(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
  LCD_WrCmd(0x81);//--set contrast control register
  LCD_WrCmd(0xcf); // Set SEG Output Current Brightness
  LCD_WrCmd(0xa1);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
  LCD_WrCmd(0xc8);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
  LCD_WrCmd(0xa6);//--set normal display
  LCD_WrCmd(0xa8);//--set multiplex ratio(1 to 64)
  LCD_WrCmd(0x3f);//--1/64 duty
  LCD_WrCmd(0xd3);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
  LCD_WrCmd(0x00);//-not offset
  LCD_WrCmd(0xd5);//--set display clock divide ratio/oscillator frequency
  LCD_WrCmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
  LCD_WrCmd(0xd9);//--set pre-charge period
  LCD_WrCmd(0xf1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
  LCD_WrCmd(0xda);//--set com pins hardware configuration
  LCD_WrCmd(0x12);
  LCD_WrCmd(0xdb);//--set vcomh
  LCD_WrCmd(0x40);//Set VCOM Deselect Level
  LCD_WrCmd(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
  LCD_WrCmd(0x02);//
  LCD_WrCmd(0x8d);//--set Charge Pump enable/disable
  LCD_WrCmd(0x14);//--set(0x10) disable
  LCD_WrCmd(0xa4);// Disable Entire Display On (0xa4/0xa5)
  LCD_WrCmd(0xa6);// Disable Inverse Display On (0xa6/a7)
  LCD_WrCmd(0xaf);//--turn on oled panel
  LCD_Fill(0x00);  //初始清屏
  LCD_Set_Pos(0, 0);
}


/***************功能描述：显示6*8一组标准ASCII字符串	显示的坐标（x,y），y为页范围0～7****************/
void LCD_P6x8Str(unsigned char x, unsigned char y, char *ch)
{
  unsigned int i;
  char *p_ch = NULL;
  unsigned int chr;

  for (p_ch = ch; *p_ch != '\0'; p_ch++) {
      chr = *p_ch - 32;
      if (x > 126) {
          x = 0;
          y++;
      }
      LCD_Set_Pos(x, y);
      for (i = 0; i < 6; i++) {
          LCD_WrDat(F6x8[chr][i]);
      }
      x += 6;
  }
}


/*******************功能描述：显示8*16一组标准ASCII字符串	 显示的坐标（x,y），y为页范围0～7****************/
void LCD_P8x16Str(unsigned char x, unsigned char y, char *ch)
{
  unsigned int i;
  char *p_ch = NULL;
  unsigned int chr;

  for (p_ch = ch; *p_ch != '\0'; p_ch++) {
      chr = *p_ch - 32;
      if (x > 120) {
          x = 0;
          y++;
      }
      LCD_Set_Pos(x, y);
      for (i = 0; i < 8; i++) {
          Serial.println(chr);
          LCD_WrDat(F8X16[chr * 16 + i]);
      }
      LCD_Set_Pos(x, y + 1);
      for (i = 0; i < 8; i++) {
          LCD_WrDat(F8X16[chr * 16 + i + 8]);
      }
      x += 8;
  }
}



/*****************功能描述：显示16*16点阵  显示的坐标（x,y），y为页范围0～7****************************/
void LCD_P16x16Ch(unsigned char x, unsigned char y, unsigned char N)
{
    unsigned char wm = 0;
    unsigned int adder = 32 * N;

    LCD_Set_Pos(x, y);
    for (wm = 0; wm < 16; wm++) {
        LCD_WrDat(F16x16[adder]);
        adder += 1;
    }
    LCD_Set_Pos(x, y + 1);
    for (wm = 0; wm < 16; wm++) {
        LCD_WrDat(F16x16[adder]);
        adder += 1;
    }
}


/***********功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7*****************/
void Draw_BMP(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, const unsigned char BMP[])
{
  unsigned int j=0;
  unsigned int x,y;

  if(y1%8==0) y=y1/8;
  else y=y1/8+1;
  for(y=y0;y<y1;y++)
  {
    LCD_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
    {
      LCD_WrDat(BMP[j++]);
    }
  }
}
