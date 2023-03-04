/******************************************************************
********************************************************************	
*	Date: 	Mar 4, 2023        
*	Author:	M_Samy
*	SWC:	
*	Ver:	
*******************************************************************
*******************************************************************/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "LED_config.h"

void App_SysTick_Callback(void*);
void HAL_LED_init(void);

void HAL_LED_ON(uint8);
void HAL_LED_OFF(uint8);
void HAL_LED_TOG(uint8);


#endif // LED_INTERFACE_H_
