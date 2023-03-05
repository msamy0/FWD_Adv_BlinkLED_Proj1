/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    NVIC Configuration
* Module :      NVIC Module
* Description: 	For driver user to config NVIC module depending on target and application
* REV:  				1.0
* DATE:
* AUTHOR:       M. Samy
*
************************************************************************************************************************/
#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_

#include "NVIC_private.h"

/* Select ARM Based Target [ARM_TM4C123GH6PM , To be Continued...]*/
#define NVIC_Target ARM_TM4C123GH6PM

/* Select Grouping scheme for NVIC 
 * ARM_TM4C123GH6PM -> G8_S0(0x04) , G4_S2(0x05) , G2_S4(0x06) , G0_S8(0x07)
 * STM32            -> To be continued...
 */
#define NVIC_PriorityGrouping    0x04

/* Error handling */
#if NVIC_Target == 0
	#error "NVIC driver have no proper target, kindly select one !"
//#else
//	#if NVIC_Target == ARM_TM4C123GH6PM
//		#define NVIC_INT_QTY   155
//	#endif
//	#if NVIC_Target == ARM_TM4C123GH6PM && (NVIC_PriorityGrouping < 0x04 || NVIC_PriorityGrouping > 0x07)
//		#error "Kindly, select prober NVIC grouping"
//	#endif
#endif

static const NVIC_ConfigTableDatatype NVIC_ConfigTableUserInput[] =
{

/*
{InterruptName                     ,Enable          ,Priority        ,Event Trigger   ,LevelTrigger    } */
{INT_Name_SysTick_15               ,INT_NOT_ASSIGNED,0               ,INT_DEFAULT     ,INT_DEFAULT     },
{INT_Name_GPIOPortD_19             ,INT_ENABLED     ,1               ,INT_DEFAULT     ,INT_DEFAULT     },

};

#endif
