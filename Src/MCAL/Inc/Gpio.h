

#ifndef GPIO_H
#define GPIO_H

#include "STD_Types.h"
#include "TM4C123GH6PM.h"

typedef struct
{
	uint32 LOCK;
	uint32 CR;
	uint32 AMSEL;
	uint32 PCTL;
	uint32 DIR;
	uint32 AFSEL;
	uint32 PUR;
	uint32 DEN;
}config;

void GPIO_Init(GPIOA_Type* GPIO_Port, config* cfg);
void GPIO_WriteChannel(GPIOA_Type* GPIO_Port, uint8 channelPosition, STD_levelType level);
STD_levelType GPIO_ReadChannel(GPIOA_Type* GPIO_Port, uint8 channelPosition);
#endif