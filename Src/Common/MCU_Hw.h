#ifndef MCU_H
#define MCU_H

#include "STD_Types.h"
/*
typedef struct
{
	uint32 VECACT			:8;
	uint32						:3;
	uint32 RETBASE		:1;
	uint32 VECPEND		:8;
	uint32 						:2;
	uint32	ISRPEND		:1;
	uint32	ISRPRE		:1;
	uint32						:1;
	uint32	PENDSTCLR	:1;
	uint32	PENDSTSET	:1;
	uint32	UNPENDSV	:1;
	uint32	PENDSV		:1;
	uint32						:2;
	uint32	NMISET		:1;
}INTCTRL_BF;


typedef union
{
	uint32 Reg;
	INTCTRL_BF BF;
}INTCTRL_Tag;

typedef struct
{
	uint32	VECTRESET			:1;
	uint32	VECTCLRACT		:1;
	uint32 SYSRESREQ			:1;
	uint32 								:5;
	uint32 PRIGROUP				:3;
	uint32								:4;
	uint32	ENDIANESS			:1;
	uint32	VECTKEY				:16;
}APINT_BF;


typedef union
{
	uint32 Reg;
	APINT_BF BF;
}APINT_Tag;*/


#define	GET_REG_ADDRESS(Base,Offset)	(*((volatile uint32*)((Base)+(Offset))))

#define PERIP_BASE_ADDRESS	0xE000E000
#define NVIC_BASE_ADDRESS		0xE000E100
#define	PRI_BASE_ADDRESS		0xE000E400

#define	APINT_VECTKEY					0x05FA

#define 		APINT				GET_REG_ADDRESS(PERIP_BASE_ADDRESS,0xD0C)
#define 		INTCTRL			GET_REG_ADDRESS(PERIP_BASE_ADDRESS,0xD04)





#endif
