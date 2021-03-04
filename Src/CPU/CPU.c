#include "CPU.h"

void CPU_EnableException (CPU_ExceptionType exceptionType)
{
	if(exceptionType == CPU_Programmable)
	{
		asm("CPSIE i");
	}else if(exceptionType == CPU_Fault)
	{
		asm("CPSIE f");
	}
	
	/* Switch to user mode */
	asm("MOV R0, #0x01");
	asm("MSR CONTROL, R0");
}
void CPU_DisableException (CPU_ExceptionType exceptionType)
{
	if(exceptionType == CPU_Programmable)
	{
		asm("CPSID i");
	}else if(exceptionType == CPU_Fault)
	{
		asm("CPSID f");
	}
	
	/* Switch to user mode */
	asm("MOV R0, #0x01");
	asm("MSR CONTROL, R0");
}
