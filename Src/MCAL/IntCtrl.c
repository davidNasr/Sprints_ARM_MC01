
#include "IntCtrl.h"

void IntCtrl_Init(void)
{
	uint8 	i=0;
	uint32 	enRegOffset=0;
	uint32 	enBitOffset=0;
	uint32	priRegOffset=0;
	uint32 	priBitOffset=0;
	uint8		grpPriorityLoc=0;
	

	
	APINT = (APINT_VECTKEY<<16U) | (NVIC_PRIORITY_SYSTEM<<8U);
	
	for(i=0; i<SUPPORTED_INTERRUPTS_NUMBER; i++)
	{
		enRegOffset = (NVIC_Cfg[i].interruptName/BUS_WIDTH)*WORD_LENGTH;			//each EN reg has 32 bits, each bit enable the corresponding interrupt
		enBitOffset = NVIC_Cfg[i].interruptName%BUS_WIDTH;
			
		SET_BIT(GET_REG_ADDRESS(NVIC_BASE_ADDRESS,enRegOffset),enBitOffset);	//set the corresponding bit in the EN register
		
		
			#if	NVIC_PRIORITY_SYSTEM == NVIC_SYSTEM_XXX
					grpPriorityLoc = NVIC_Cfg[i].grpPriority;
			#elif	NVIC_PRIORITY_SYSTEM == NVIC_SYSTEM_XXY
					grpPriorityLoc = ((NVIC_Cfg[i].grpPriority<<1)&0x6)|(NVIC_Cfg[i].subGrpPriority&0x1);
			#elif	NVIC_PRIORITY_SYSTEM == NVIC_SYSTEM_XYY
					grpPriorityLoc = ((NVIC_Cfg[i].grpPriority<<2)&0x4)|(NVIC_Cfg[i].subGrpPriority&0x3);
			#elif	NVIC_PRIORITY_SYSTEM == NVIC_SYSTEM_YYY
					grpPriorityLoc = NVIC_Cfg[i].grpPriority;
		
			#endif
		
		priRegOffset = (NVIC_Cfg[i].interruptName/4U)*WORD_LENGTH;
		priBitOffset = 5 + (8*(NVIC_Cfg[i].interruptName%4U));
		
		GET_REG_ADDRESS(PRI_BASE_ADDRESS,priRegOffset) |= (grpPriorityLoc << priBitOffset);
			
	
	}
	
	
	
	
	
	


}