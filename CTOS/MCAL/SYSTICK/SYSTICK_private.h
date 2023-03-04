/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    SysTick Private
* Module :      SysTick Module
* Description:  For private sections that are not accessed outside this module
* REV:  		1.0
* DATE:			2023
* Autor: 		M. Samy
*
************************************************************************************************************************/
#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

/*- INCLUDES
------------------------------------------------------------------------------*/
#include "STD_Types.h"
#include "BIT_MATH.h"

/*- LOCAL MACROS
------------------------------------------------------------------------------*/
#define STICK_STCTRL     *((volatile uint32*) (0xE000E010))
#define STICK_STRELOAD   *((volatile uint32*) (0xE000E014))
#define STICK_STCURRENT  *((volatile uint32*) (0xE000E018))

#define STCTRL_EnableBit       0x00
#define STCTRL_IntEnBit        0x01
#define STCTRL_ClkSrcBit       0x02
#define STCTRL_CountBit        0x10

#define SystemClock   0
#define InternalClock 1
/*- LOCAL DATATYPES
------------------------------------------------------------------------------*/

typedef enum 
{
	STICK_LOWBit,
	STICK_HIGHBit,
	STICK_SuccessfulOperation,
	STICK_InputError,
} STICK_ErrorHandlerType;

typedef enum
{
	STICK_Enable,
	STICK_Disable
} STICK_EnableType;
	
#endif // SYSTICK_PRIVATE_H_


















