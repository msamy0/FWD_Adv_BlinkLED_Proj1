/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    SysTick Implementation file
* Module :      SysTick Module
* Description:  Implementation of Functions and APIs
* REV:  		1.0
* DATE:			2023
* Autor: M. Samy
************************************************************************************************************************/
/*
 * ToDo :-
 *
 * */
/*- INCLUDES
------------------------------------------------------------------------------*/
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"

#ifdef STICK_UseSysTick

/*- LOCAL VARIABLES
------------------------------------------------------------------------------*/
/* Pointer to function that takes argument of (pointer to void), the function then returns void */
static void (*STICK_vPtrFuncHandler)(void *) = NULL;

/* CallBackArgument Pointer*/
static void (*CBAptr)= NULL;

/*- LOCAL FUNCTION PROTOTYPES
------------------------------------------------------------------------------*/
static STICK_ErrorHandlerType SysTick_SetReloadValue(uint32);


/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------------------------------------------------------------*/
static STICK_ErrorHandlerType SysTick_SetReloadValue(uint32 u32ReloadValue)
{
	if (u32ReloadValue > 0x00FFFFFFUL)
	{
		return STICK_InputError;
	}
	else
	{
		STICK_STRELOAD = u32ReloadValue;
		return STICK_SuccessfulOperation;
	}

}

/*- APIS IMPLEMENTATION
------------------------------------------------------------------------------*/

STICK_ErrorHandlerType SysTick_CallbackRegister(void (*CallbackFunction)(void *), void *ptr)
{
	if (CallbackFunction != NULL)
	{
		STICK_vPtrFuncHandler = CallbackFunction;
		CBAptr = ptr;
		return STICK_SuccessfulOperation;
	}
	else
	{
		return STICK_InputError;
	}
}

STICK_ErrorHandlerType SysTick_init(void)
{
	/* Set clock source for systick*/
	if (STICK_ClockSource == SystemClock)
	{
		SET_BIT(STICK_STCTRL,STCTRL_ClkSrcBit);
	}
	else
	{
		CLEAR_BIT(STICK_STCTRL,STCTRL_ClkSrcBit);
	}

	/* Set the initial reload value of systick to start decrement from*/
	if (SysTick_SetReloadValue(STICK_initReloadvalue) == STICK_InputError)
	{
		return STICK_InputError;
	}

	/* Enable or leave unchanged the systick timer interrupt */
	#ifdef STICK_UseInterrupt
		SET_BIT(STICK_STCTRL,STCTRL_IntEnBit);
	#endif

	return STICK_SuccessfulOperation;
}

STICK_ErrorHandlerType SysTick_GetCountFlag()
{
	if (GET_BIT(STICK_STCTRL,STCTRL_CountBit))
	{
		return STD_HIGH;
	}
	else
	{
		return STD_LOW;
	}
}

STICK_ErrorHandlerType SysTick_EnableDisable(STICK_EnableType Action)
{
	if (Action == STICK_Enable)
	{
		SET_BIT(STICK_STCTRL, STCTRL_EnableBit);
	}
	else
	{
		CLEAR_BIT(STICK_STCTRL, STCTRL_EnableBit);
	}
	return STICK_SuccessfulOperation;
}

STICK_ErrorHandlerType SysTick_SetReloadMillis(uint32 requiredMillis)
{
	uint32 SysTick_Frequency = (STICK_CPUFreq/1000000UL);
	double tickPeriod =(1/(double)SysTick_Frequency);	//CAUTATION: Assuming SYSDIV is not enabled
	double reloadValue =( (double) requiredMillis *1000.00) / (double)tickPeriod;

	if ((uint32)reloadValue > 0xFFFFFF)
	{
		return STICK_InputError;
	}
	else
	{
		SysTick_SetReloadValue((uint32)reloadValue);
		return STICK_SuccessfulOperation;
	}
}

#ifdef STICK_UseInterrupt
void SysTick_Handler(void)
{
	if (STICK_vPtrFuncHandler != NULL)
	{
		(*STICK_vPtrFuncHandler)(CBAptr);
	}
	uint8 x =  GET_BIT(STICK_STCTRL,STCTRL_CountBit);
}
#endif


#endif
