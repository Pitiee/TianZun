#include "Pitie.h"

void PA(uint Pin,uchar Value)
{
	if(Value)HAL_GPIO_WritePin(GPIOA,0x0001<<Pin,GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA,0x0001<<Pin,GPIO_PIN_RESET);
}
void PB(uint Pin,uchar Value)
{
	if(Value)HAL_GPIO_WritePin(GPIOB,0x0001<<Pin,GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOB,0x0001<<Pin,GPIO_PIN_RESET);
}
void PC(uint Pin,uchar Value)
{
	if(Value)HAL_GPIO_WritePin(GPIOC,0x0001<<Pin,GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOC,0x0001<<Pin,GPIO_PIN_RESET);
}
void PD(uint Pin,uchar Value)
{
	if(Value)HAL_GPIO_WritePin(GPIOD,0x0001<<Pin,GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOD,0x0001<<Pin,GPIO_PIN_RESET);
}
void PE(uint Pin,uchar Value)
{
	if(Value)HAL_GPIO_WritePin(GPIOE,0x0001<<Pin,GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOE,0x0001<<Pin,GPIO_PIN_RESET);
}

