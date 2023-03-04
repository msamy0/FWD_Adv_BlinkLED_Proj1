/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    GPOI Configuration
* Module :      GPIO Module
* Description:  For compile configuration of GPIO Module
* REV:  		1.0
* DATE:			2023
* Autor: M. Samy
*
************************************************************************************************************************/
#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_
/*- INCLUDES
------------------------------------------------------------------------------*/
#include "GPIO_private.h"


/* Select ARM Based Target [ARM_TM4C123GH6PM , To be Continued...]*/
#define GIOP_Target 	ARM_TM4C123GH6PM
/* Select Addressing Path  [ARM_APB , To be Continued...]*/
#define GIOP_TargetPath ARM_APB


static const GPIO_UserConfigStructType GPIO_ConfigTableUserInput[] =
{
/*PinName   ,PinDirection  ,PinMode         ,Current     ,PinInternalAttach*/
{GPIO_PinF1 ,GPIO_PinOutut ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullUp},
{GPIO_PinF2 ,GPIO_PinOutut ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullUp},
{GPIO_PinF3 ,GPIO_PinOutut ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullUp},
{GPIO_PinC0 ,GPIO_PinInput ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullDown},
{GPIO_PinC1 ,GPIO_PinInput ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullDown},
};

#endif
