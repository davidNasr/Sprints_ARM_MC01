#ifndef	INTCTRL_H
#define INTCTRL_H

#include 	"STD_Types.h"
#include	"IntCtrl_Cfg.h"
#include	"Mcu_Hw.h"
#include	"CPU.h"
#include	"IntCtrl_Types.h"
#include 	"Bit_Math.h"


#define	NVIC_SYSTEM_XXX	0x4
#define	NVIC_SYSTEM_XXY	0x5
#define	NVIC_SYSTEM_XYY	0x6
#define	NVIC_SYSTEM_YYY	0x7



typedef struct
{
	INTCTRL_Type	interruptName;
	uint8					grpPriority;
	uint8					subGrpPriority;
}NVIC_Cfg_Type;


extern const NVIC_Cfg_Type NVIC_Cfg [];

void IntCtrl_Init(void);



#endif
