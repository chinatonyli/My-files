/********************************************
 * OLED屏测试程序-STC&89C52 
 * 技术支持淘宝：http://cecsaler.taobao.com
 *********************************************************/
#include <SPI.h>
#include "codetab.h"
#include "LQ12864.h"


void setup(void) 
{
    Serial.begin(9600);

    pinMode(10, OUTPUT);
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);
    SPI.setClockDivider(SPI_CLOCK_DIV64);

    lcd_init();
    //lcd_P8x16Str(0, 0, "aaaaaaaaaaaaaaaa");   
}


void loop(void)
{
    unsigned int i;   
    for (i = 0; i < 8; i++) {
        lcd_P16x16Ch(i * 16, 0, i);  //点阵显示
        lcd_P16x16Ch(i * 16, 2, i + 8);
        lcd_P16x16Ch(i * 16, 4, i + 16);
        lcd_P16x16Ch(i * 16, 6, i + 24);
    }

    //lcd_P8x16Str(44, 0, "SALER");   
    //lcd_P8x16Str(20, 2, "OLEDDISPLAY");
    //lcd_P8x16Str(8,  4, "TEL: 13882007987");   

    /*
    lcd_P6x8Str(16, 6, "445022363@qq.com"); 
    lcd_P6x8Str(34, 7, "2012-06-19");    
    delay(1000);
    */

    /*
    lcd_clear();
    lcd_draw_bmp(0, 0, 128, 8, BMP);  //图片显示
    */
}
