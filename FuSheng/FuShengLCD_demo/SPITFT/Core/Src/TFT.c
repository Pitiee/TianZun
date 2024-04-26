#include "TFT.h"


void DatTo7735(uint8_t byte)
{
	uint8_t data[1] = {byte};
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
	HAL_SPI_Transmit(&hspi1, data, 1, 0xffff);
}

void ComTo7735(uint8_t byte)
{
	uint8_t data[1] = {byte};
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, data, 1, 0xffff);
}


void ST7735_Init()
{
  //----ST7735S reset sequence----------------//
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
  HAL_Delay(5);      
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
  HAL_Delay(5);    
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
  HAL_Delay(20);    
	//--------------------------------End ST7735R Reset Sequence --------------------------------------//

	//--------------------------------End ST7735S Reset Sequence --------------------------------------//
	ComTo7735(0x11); //Sleep out
	HAL_Delay(120);              //Delay 120ms
	//------------------------------------ST7735S Frame Rate-----------------------------------------//
	ComTo7735(0xB1);
	DatTo7735(0x05);
	DatTo7735(0x3C);
	DatTo7735(0x3C);
	ComTo7735(0xB2);
	DatTo7735(0x05);
	DatTo7735(0x3C);
	DatTo7735(0x3C);
	ComTo7735(0xB3);
	DatTo7735(0x05);
	DatTo7735(0x3C);
	DatTo7735(0x3C);
	DatTo7735(0x05);
	DatTo7735(0x3C);
	DatTo7735(0x3C);
	//------------------------------------End ST7735S Frame Rate---------------------------------//
	ComTo7735(0xB4); //Dot inversion
	DatTo7735(0x03);
	//------------------------------------ST7735S Power Sequence---------------------------------//
	ComTo7735(0xC0);
	DatTo7735(0x28);
	DatTo7735(0x08);
	DatTo7735(0x04);
	ComTo7735(0xC1);
	DatTo7735(0XC0);
	ComTo7735(0xC2);
	DatTo7735(0x0D);
	DatTo7735(0x00);
	ComTo7735(0xC3);
	DatTo7735(0x8D);
	DatTo7735(0x2A);
	ComTo7735(0xC4);
	DatTo7735(0x8D);
	DatTo7735(0xEE);
	//---------------------------------End ST7735S Power Sequence-------------------------------------//
	ComTo7735(0xC5); //VCOM
	DatTo7735(0x1A);
	ComTo7735(0x36); //MX, MY, RGB mode
	DatTo7735(0xC0);
	//------------------------------------ST7735S Gamma Sequence---------------------------------//
	ComTo7735(0xE0);
	DatTo7735(0x04);
	DatTo7735(0x22);
	DatTo7735(0x07);
	DatTo7735(0x0A);
	DatTo7735(0x2E);
	DatTo7735(0x30);
	DatTo7735(0x25);
	DatTo7735(0x2A);
	DatTo7735(0x28);
	DatTo7735(0x26);
	DatTo7735(0x2E);
	DatTo7735(0x3A);
	DatTo7735(0x00);
	DatTo7735(0x01);
	DatTo7735(0x03);
	DatTo7735(0x13);
	ComTo7735(0xE1);
	DatTo7735(0x04);
	DatTo7735(0x16);
	DatTo7735(0x06);
	DatTo7735(0x0D);
	DatTo7735(0x2D);
	DatTo7735(0x26);
	DatTo7735(0x23);
	DatTo7735(0x27);
	DatTo7735(0x27);
	DatTo7735(0x25);
	DatTo7735(0x2D);
	DatTo7735(0x3B);
	DatTo7735(0x00);
	DatTo7735(0x01);
	DatTo7735(0x04);
	DatTo7735(0x13);
	//------------------------------------End ST7735S Gamma Sequence-----------------------------//
	ComTo7735(0x3A); //65k mode
	DatTo7735(0x05);
	ComTo7735(0x29); //Display on
}

	void DISP_WINDOWS(void)
{
	ComTo7735(0x2a);
	DatTo7735(0x00); 
	DatTo7735(26); 
	DatTo7735(0x00); 	
	DatTo7735(105); 

	ComTo7735(0x2b);
	DatTo7735(0x00);
	DatTo7735(1);
	DatTo7735(0x00);	
	DatTo7735(160);	
	
	ComTo7735(0x2c);
	
}
	void DISPLAY_COLOR(uint16_t color)
{
	uint16_t i;
	DISP_WINDOWS();
	for (i=160*80;i>0;i--)
	{
			DatTo7735(color>>8);
			DatTo7735(color);
	}
}

