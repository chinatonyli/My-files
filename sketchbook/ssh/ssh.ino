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

    LCD_Init();
}


void loop(void)
{
    Serial.println("Ok");
    LCD_CLS();   
    unsigned int i;   
    for (i = 0; i < 8; i++) {
        LCD_P16x16Ch(i * 16, 0, i);
        LCD_P16x16Ch(i * 16, 2, i + 8);
        LCD_P16x16Ch(i * 16, 4, i + 16);
        LCD_P16x16Ch(i * 16, 6, i + 24);
    } 

    delay(1000); 
    LCD_CLS();   

    LCD_P8x16Str(44, 0, (char *) "saler");   
    LCD_P8x16Str(20, 2, "oleddisplay");
    //LCD_P8x16Str(8, 4, "tel:13882007987");   
    //LCD_P6x8Str(16, 6, "445022363@qq.com"); 
    //LCD_P6x8Str(34, 7, "2012-06-19");    
    //delay(1000);  
    //LCD_CLS();
    //Draw_BMP(0,0,128,8,BMP);  //图片显示
    //delayms(400);  
    delay(1000); 
    LCD_CLS();   
}
