#ifndef __PITIE_H__
#define __PITIE_H__

#include "main.h"
#include "string.h"
#include "stdio.h"

#ifdef __SPI_H__
#include "spi.h"
#endif
#ifdef __GPIO_H__
#include "gpio.h"
#endif
#ifdef __TIM_H__
#include "tim.h"
#endif
#ifdef __USART_H__
#include "usart.h"
int fputc(int ch,FILE *F)
{
	HAL_UART_Transmit(&huart1,(uint8_t *)&ch,1,0xffff);
	return ch;
}
#endif



#define uchar unsigned char
#define uint unsigned int

void PA(uint Pin,uchar Value);
void PB(uint Pin,uchar Value);
void PC(uint Pin,uchar Value);
void PD(uint Pin,uchar Value);
//void PE(uint Pin,uchar Value);

#endif
