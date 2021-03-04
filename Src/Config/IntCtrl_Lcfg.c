

#include "IntCtrl_Cfg.h"

const	NVIC_Cfg_Type	NVIC_Cfg	[SUPPORTED_INTERRUPTS_NUMBER] = 
{	/* Interrupt name					Grp priority		Sub grp priority	*/
	{NVIC_GPIO_PORT_A,					1,									0			},
	{NVIC_GPIO_PORT_B,					1,									0			},
	{UART0					 ,					3,									0			},
	{NVIC_GPIO_PORT_D,					2,									0			},

};
