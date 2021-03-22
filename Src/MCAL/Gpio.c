
#include "Gpio.h"
#include "Bit_Math.h"

void GPIO_Init(GPIOA_Type* GPIO_Port, config* cfg)
{
	if (GPIO_Port == GPIOA)
	{
		SYSCTL -> RCGC2 |= 0x01;
	}else if (GPIO_Port == GPIOB)
	{
		SYSCTL -> RCGC2 |= 0x02;
	}else if (GPIO_Port == GPIOC)
	{
		SYSCTL -> RCGC2 |= 0x04;
	}else if (GPIO_Port == GPIOD)
	{
		SYSCTL -> RCGC2 |= 0x08;
	}else if (GPIO_Port == GPIOE)
	{
		SYSCTL -> RCGC2 |= 0x10;
	}else if (GPIO_Port == GPIOF)
	{
		SYSCTL -> RCGC2 |= 0x20;
	}
	
	GPIO_Port -> LOCK = cfg -> LOCK;
	GPIO_Port -> CR = cfg -> CR;
	GPIO_Port -> AMSEL = cfg -> AMSEL;
	GPIO_Port -> PCTL = cfg -> PCTL;
	GPIO_Port -> DIR = cfg -> DIR;
	GPIO_Port -> AFSEL = cfg -> AFSEL;
	GPIO_Port -> PUR = cfg -> PUR;
	GPIO_Port -> DEN = cfg -> DEN;
}

void GPIO_WriteChannel(GPIOA_Type* GPIO_Port, uint8 channelPosition, STD_levelType level)
{
	if(level == STD_high)
	{
		SET_BIT(GPIO_Port -> DATA,channelPosition);
	}else
		{
			CLR_BIT(GPIO_Port -> DATA,channelPosition);
		}
}

STD_levelType GPIO_ReadChannel(GPIOA_Type* GPIO_Port, uint8 channelPosition)
{
	STD_levelType value = STD_low;
	
	value = GET_BIT(GPIO_Port -> DATA,channelPosition);
	
	return value;
}

	
