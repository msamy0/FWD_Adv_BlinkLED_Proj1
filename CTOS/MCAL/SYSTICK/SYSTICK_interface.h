/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    SysTick Interface
* Module :      SysTick Module
* Description:  Header to be included in the in any other module to use SysTick APIs provided here
* REV:  		1.0
* DATE:			2023
* Autor:		 M. Samy
*
************************************************************************************************************************/
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

/*- INCLUDES
------------------------------------------------------------------------------*/
#include "SYSTICK_private.h"

/*- APIs PROTOTYPES
------------------------------------------------------------------------------*/

/*******************************************************************************
* NAME : SysTick_CallbackRegister()
* ID : 0x01
* SYNC/ASYNC :
* REENTRANCY :
* PARAMETER/IN : 1- pointer to function that takes pointer to void and return void
* 				 2- pointer to void that is used to pass CallbackFunction argument
* PARAMETER/OUT : None
* PARAMETER/IN-OUT : None
* RETURN VALUE : void
* DESCRIPTION : API used to register a specific application function to be
* 				executed in the SysTick exception handler
*******************************************************************************/
STICK_ErrorHandlerType SysTick_CallbackRegister(void (*CallbackFunction)(void *), void *ptr);

/*******************************************************************************
* NAME : SysTick_SetReloadMillis()
* ID : 0x01
* SYNC/ASYNC :
* REENTRANCY :
* PARAMETER/IN :
* PARAMETER/OUT :
* PARAMETER/IN-OUT :
* RETURN VALUE :
* DESCRIPTION :
*******************************************************************************/
STICK_ErrorHandlerType SysTick_SetReloadMillis(uint32);

/*******************************************************************************
* NAME : SysTick_Enable()
* ID : 0x01
* SYNC/ASYNC :
* REENTRANCY :
* PARAMETER/IN :
* PARAMETER/OUT :
* PARAMETER/IN-OUT :
* RETURN VALUE :
* DESCRIPTION :
*******************************************************************************/
STICK_ErrorHandlerType SysTick_EnableDisable(STICK_EnableType);

/*******************************************************************************
* NAME : SysTick_GetCountFlag()
* ID : 0x01
* SYNC/ASYNC :
* REENTRANCY :
* PARAMETER/IN :
* PARAMETER/OUT :
* PARAMETER/IN-OUT :
* RETURN VALUE :
* DESCRIPTION :
*******************************************************************************/
STICK_ErrorHandlerType SysTick_GetCountFlag(void);

/*******************************************************************************
* NAME : SysTick_init()
* ID : 0x01
* SYNC/ASYNC :
* REENTRANCY :
* PARAMETER/IN :
* PARAMETER/OUT : 
* PARAMETER/IN-OUT :
* RETURN VALUE :
* DESCRIPTION : 
*******************************************************************************/
STICK_ErrorHandlerType SysTick_init(void);

#endif //SYSTICK_INTERFACE_H_
