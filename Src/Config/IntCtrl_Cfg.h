
#ifndef	INTCTRL_CFG_H
#define INTCTRL_CFG_H


#include "IntCtrl.h"

/* Choose from following:
			NVIC_SYSTEM_XXX		0-7 groups 	& 0 	sub-groups
			NVIC_SYSTEM_XXY		0-3 groups 	& 0-1 sub-groups
			NVIC_SYSTEM_XYY		0-1 groups 	& 0-3 sub-groups
			NVIC_SYSTEM_YYY		0 	groups 	& 0-7 sub-groups
*/

#define	NVIC_PRIORITY_SYSTEM								NVIC_SYSTEM_XXX
#define	SUPPORTED_INTERRUPTS_NUMBER					4



#endif
