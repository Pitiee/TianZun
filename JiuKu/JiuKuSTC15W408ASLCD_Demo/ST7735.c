#include<STC15.H>
#include"TFT.h"
#define uint unsigned int
#define uchar unsigned char
	
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


	void DISPLAY_COLOR(uint color)
{
        uint i,j;
        DISP_WINDOWS();
        for (i=160*80;i>0;i--)
				{
						DatTo7735(color>>8);
						DatTo7735(color);
				}

}






void main()
{
	/*P1M0|=  (1 << 2);
	P1M0|=  (1 << 3);
	P1M0|=  (1 << 4);
	P1M0|=  (1 << 5);	
	P1M1=0x00;

	
	P3M0|=  (1 << 7);
	P3M1=0x00;*/
	
	
	ST7735_Init();
	DISPLAY_COLOR(0x00);

	DISP_WINDOWS();
	DISPLAY_COLOR(0xf00F);

	while(1)
	{
		DISPLAY_COLOR(0x00ff);
		delay_ms(10);
		DISPLAY_COLOR(0x0f0a);
		delay_ms(10);
		DISPLAY_COLOR(0xfffa);
		delay_ms(10);
		DISPLAY_COLOR(0x0ff0);
	}
}
	