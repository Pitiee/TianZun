#ifndef __TFT_H__
#define __TFT_H__
#include "main.h"
#include "spi.h"
#include "gpio.h"



void DatTo7735(uint8_t byte);
void ComTo7735(uint8_t byte);
void DISP_WINDOWS(void);
void ST7735_Init(void);
void DISPLAY_COLOR(uint16_t color);


#endif
