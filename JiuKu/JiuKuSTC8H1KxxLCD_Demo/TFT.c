#include<STC8H.H>
#include"TFT.h"




void SPI_Init();         //spi��ʼ��
void DatToSPI(uint out);     //spiдһ���ֽ�
void ST7735_Init();			//TFT��ʼ��
void ComTo7735(uint byte);
void DatTo7735(uint byte);
void delay_ms(uint xms);

//========================================================================
// ����: SPI��ʼ��.
// ����: speed:ͨ�����ʣ�0~3��.//ɾ��
// ����: none.
//========================================================================
void SPI_Init()
{
/*
    SPCTL |=  (1 << 7);         //���� SS ���Ź��ܣ�ʹ�� MSTR ȷ���������������Ǵӻ�
    SPCTL |=  (1 << 6);         //ʹ�� SPI ����
    SPCTL &= ~(1 << 5);         //�ȷ���/�������ݵĸ�λ�� MSB��
    SPCTL |=  (1 << 4);         //��������ģʽ
    SPCTL &= ~(1 << 3);         //����CPOL  
    SPCTL |=  (HARDSPI_CPOL << 3);

    SPCTL &= ~(1 << 2);         //����CPHA
    SPCTL |=  (HARDSPI_CPHA << 2);

    SPCTL = (SPCTL & ~3) | 3;           //SPI ʱ��Ƶ��ѡ��, 0: 4T, 1: 8T,  2: 16T,  3: 32T
	
*/
		SPCTL=0xd0;
	
	
    //P_SW1 = (P_SW1 & ~(3<<2));// | (1<<2); //IO���л�. 0: P1.2/P5.4 P1.3 P1.4 P1.5,      1: P2.2 P2.3 P2.4 P2.5,     2: P5.4 P4.0 P4.1 P4.3,     3: P3.5 P3.4 P3.3 P3.2

    SCL = 0;        //��ʱ������Ϊ�ͳ�ʼ״̬
    SDA = 1;
		
    SPSTAT = 0xc0;   //��0 SPIF��WCOL��־
}

//========================================================================
// ����: SPIдһ���ֽ�.
// ����: none.
// ����: none.
//========================================================================
void DatToSPI(uint out)
{
    SPDAT = out;
    while((SPSTAT & 0x80) == 0) ;
    SPSTAT = 0xc0;   //��0 SPIF��WCOL��־
}

//========================================================================
// ����: TFTд����.
// ����: none.
// ����: none.
//========================================================================
void ComTo7735(uint byte)
{
	RS=0;
	CS=0;
	DatToSPI(byte);
	CS=1;
}

//========================================================================
// ����: TFTд����.
// ����: none.
// ����: none.
//========================================================================
void DatTo7735(uint byte)
{
	RS=1;
	CS=0;
	DatToSPI(byte);
	CS=1;
}

//========================================================================
// ����: TFT��ʼ��.
// ����: none.
// ����: none.
//========================================================================
void ST7735_Init()
{
	SPI_Init();
  //----ST7735S reset sequence----------------//
	RES=1;
  delay_ms(5);      
  RES=0;
  delay_ms(5);     
  RES=1;
  delay_ms(20);    


//--------------------------------End ST7735R Reset Sequence --------------------------------------//

//--------------------------------End ST7735S Reset Sequence --------------------------------------//
ComTo7735(0x11); //Sleep out
delay_ms(120);              //Delay 120ms
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

void delay_ms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
	   for(j=1600;j>0;j--);
}
