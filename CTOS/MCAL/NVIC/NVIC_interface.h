/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    NVIC interface Lib
* Module :      NVIC Module
* Description: 	Interfacing for NVIC prephiral, Tiva C Hardware
* REV:  				1.0
* DATE: 
* AUTHOR:				M. Samy
*
************************************************************************************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/*- INCLUDES
------------------------------------------------------------------------------*/
#include "BIT_MATH.h"
#include "STD_Types.h"


/*- APIs PROTOTYPES
------------------------------------------------------------------------------*/
/*******************************************************************************
* NAME : NVIC_init
* ID : 0x01
* SYNC/ASYNC : ASYNC
* REENTRANCY : NON-RE
* PARAMETER/IN : N/A
* PARAMETER/OUT : N/A
* PARAMETER/IN-OUT :
* RETURN VALUE : OK, NOK
* DESCRIPTION : Function to init the driver according to driver user configuration
								that have been done inside NVIC_config.h file
*******************************************************************************/
STD_DriverErrHandlerType NVIC_Init(void);

#endif /* NVIC_INTERFACE_H_ */
