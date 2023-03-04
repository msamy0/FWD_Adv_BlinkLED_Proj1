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
STD_DriverErrHandlerType NVIC_Init(void);

#endif /* NVIC_INTERFACE_H_ */
