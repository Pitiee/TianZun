#ifndef     __TFT_H__
#define     __TFT_H__
#define uint unsigned int
#define uchar unsigned char

#define CS P12
#define SCL P15
#define SDA P13
#define RS P20
#define RES P54


void SPI_Init();         //spi初始化
void DatToSPI(uint out);     //spi写一个字节
void ST7735_Init();			//TFT初始化
void ComTo7735(uint byte);
void DatTo7735(uint byte);
void delay_ms(uint xms);



#endif