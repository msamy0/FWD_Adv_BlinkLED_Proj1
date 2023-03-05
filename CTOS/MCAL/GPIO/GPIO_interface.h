/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    GPOI Interface
* Module :      GPIO Module
* Description:  Header to be included in the in any other module to use GPIO APIs provided here
* REV:  		1.0
* DATE:			2023
* Autor: M. Samy
*
************************************************************************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*- INCLUDES
------------------------------------------------------------------------------*/
#include "GPIO_private.h"

/*- APIs PROTOTYPES
------------------------------------------------------------------------------*/
/*******************************************************************************
* NAME : GPIO_ChannelDirectionSet
* ID : 0x01
* SYNC/ASYNC : SYNC (Must Enable Clock for GPIO peripheral)
* REENTRANCY : Reentrant
* PARAMETER/IN : REQUIRED PIN to be set, DIRECTION of the pin
* PARAMETER/OUT : 
* PARAMETER/IN-OUT : N/A
* RETURN VALUE : GPIO_ReadLOW | GPIO_ReadHIGH | GOIP_InputErr
* DESCRIPTION : 
*******************************************************************************/
GPIO_ErrorHandlerType GPIO_ChannelDirectionSet(GPIO_PinNameType, GPIO_PinDirectionType);


/*******************************************************************************
* NAME : GPIO_ChannelRead
* ID : 0x02
* SYNC/ASYNC : SYNC (Must Set Direction first)
* REENTRANCY : Reentrant (Using GPIODATA Bit Addressing)
* PARAMETER/IN : REQUIRED PIN to be read
* PARAMETER/OUT : 
* PARAMETER/IN-OUT : N/A
* RETURN VALUE : GPIO_ReadLOW | GPIO_ReadHIGH | GOIP_InputErr
* DESCRIPTION :
*******************************************************************************/
GPIO_ErrorHandlerType GPIO_ChannelRead(GPIO_PinNameType);

/*******************************************************************************
* NAME : GPIO_ChannelWrite
* ID : 0x03
* SYNC/ASYNC : SYNC (Must Set Direction first)
* REENTRANCY : Reentrant (Using GPIODATA Bit Addressing)
* PARAMETER/IN : REQUIRED PIN to be write - VALUE to be written
* PARAMETER/OUT : 
* PARAMETER/IN-OUT : N/A
* RETURN VALUE : GPIO_Successful | GOIP_InputErr,
* DESCRIPTION :
*******************************************************************************/
GPIO_ErrorHandlerType  GPIO_ChannelWrite(GPIO_PinNameType, GPIO_PinLevelType);

/*******************************************************************************
* NAME : GPIO_ChannelToggle
* ID : 0x04
* SYNC/ASYNC : SYNC (Must Set Direction first)
* REENTRANCY : Non_Reentrant
* PARAMETER/IN : REQUIRED PIN to be Toggled
* PARAMETER/OUT : 
* PARAMETER/IN-OUT : N/A
* RETURN VALUE : GPIO_Successful | GOIP_InputErr
* DESCRIPTION :
*******************************************************************************/
GPIO_ErrorHandlerType GPIO_ChannelToggle(GPIO_PinNameType);

/*******************************************************************************
* NAME : GPIO_PortRead
* ID : 0x05
* SYNC/ASYNC : SYNC (Must Set Port Direction First)
* REENTRANCY : Reentrant
* PARAMETER/IN : REQUIRED PORT to be read
* PARAMETER/OUT : 
* PARAMETER/IN-OUT : N/A
* RETURN VALUE :   (+ 16-bit) Represents port reading
*                | (256)      Represents error in the input
* DESCRIPTION :
*******************************************************************************/
uint16 GPIO_PortRead(GPIO_PortNameType);

/*******************************************************************************
* NAME : GPIO_PortWrite
* ID : 0x06
* SYNC/ASYNC : SYNC (Must Set Port Direction First)
* REENTRANCY : Reentrant
* PARAMETER/IN : REQUIRED PORT to be write - VALUE to be written
* PARAMETER/OUT :
* PARAMETER/IN-OUT : N/A
* RETURN VALUE : GPIO_Successful | GOIP_InputErr
* DESCRIPTION :
*******************************************************************************/
GPIO_ErrorHandlerType GPIO_PortWrite(GPIO_PortNameType, uint8 u8LocalPortLevel);

/*******************************************************************************
* NAME : GPIO_PortClockSet
* ID : 0x07
* SYNC/ASYNC :
* REENTRANCY :
* PARAMETER/IN :
* PARAMETER/OUT :
* PARAMETER/IN-OUT :
* RETURN VALUE : GPIO_Successful | GOIP_InputErr
* DESCRIPTION :
*******************************************************************************/
GPIO_ErrorHandlerType GPIO_PortClockSet(GPIO_PinNameType);

/*******************************************************************************
* NAME : GPIO_ChannelMode
* ID : 0x08
* SYNC/ASYNC :
* REENTRANCY :
* PARAMETER/IN :
* PARAMETER/OUT :
* PARAMETER/IN-OUT :
* RETURN VALUE : GPIO_Successful | GOIP_InputErr
* DESCRIPTION :
*******************************************************************************/
GPIO_ErrorHandlerType GPIO_ChannelMode(GPIO_PinNameType, GPIO_PinModeType);

/*******************************************************************************
* NAME : GPIO_ChannelAttach
* ID : 0x09
* SYNC/ASYNC :
* REENTRANCY :
* PARAMETER/IN :
* PARAMETER/OUT :
* PARAMETER/IN-OUT :
* RETURN VALUE : GPIO_Successful | GOIP_InputErr
* DESCRIPTION :
*******************************************************************************/
GPIO_ErrorHandlerType GPIO_ChannelAttach(GPIO_PinNameType, GPIO_PinInternalAttachType);

/*******************************************************************************
* NAME : GPIO_ChannelInterrupt
* ID : 0x10
* SYNC/ASYNC :
* REENTRANCY :
* PARAMETER/IN :
* PARAMETER/OUT :
* PARAMETER/IN-OUT :
* RETURN VALUE : GPIO_Successful | GOIP_InputErr
* DESCRIPTION :
*******************************************************************************/
GPIO_ErrorHandlerType GPIO_ChannelInterrupt(GPIO_PinNameType, GPIO_InterruptEnableType, GPIO_InterruptEventType, GPIO_InterruptLevelType );

/* ToDo :- API for pad current setting*/
/* ToDo :- API for Alternative function setting*/
/* ToDo :- API for committing and locking feature*/


/*******************************************************************************
* NAME : GPIO_D_CallbackRegister
* ID : 0x11
* SYNC/ASYNC :
* REENTRANCY :
* PARAMETER/IN :
* PARAMETER/OUT :
* PARAMETER/IN-OUT :
* RETURN VALUE : GPIO_Successful | GOIP_InputErr
* DESCRIPTION :
*******************************************************************************/
GPIO_ErrorHandlerType GPIO_D_CallbackRegister(void (*CallbackFunction)(void *), void *ptr);


/*******************************************************************************
* NAME : GPIO_init
* ID : 0x0*
* SYNC/ASYNC : ASYNC
* REENTRANCY : Non_Reentrant (uses Non_reentrant function )
* PARAMETER/IN :
* PARAMETER/OUT :
* PARAMETER/IN-OUT :
* RETURN VALUE :
* DESCRIPTION :
*******************************************************************************/
GPIO_ErrorHandlerType GPIO_init(void);

#endif
