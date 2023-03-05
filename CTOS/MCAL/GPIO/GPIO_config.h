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
/* Leave configuration as default in case you don't need any changes to specific feature*/
/*PinName   ,PinDirection  ,PinMode         ,Current     ,PinInternalAttach ,InterruptEnable ,InterruptEvent  ,Interrupt Level*/
{GPIO_PinF1 ,GPIO_PinOutut ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullUp    ,GPIO_INT_DEFAULT,GPIO_INT_DEFAULT,GPIO_INT_DEFAULT},
{GPIO_PinF2 ,GPIO_PinOutut ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullUp    ,GPIO_INT_DEFAULT,GPIO_INT_DEFAULT,GPIO_INT_DEFAULT},
{GPIO_PinF3 ,GPIO_PinOutut ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullUp    ,GPIO_INT_DEFAULT,GPIO_INT_DEFAULT,GPIO_INT_DEFAULT},
{GPIO_PinC0 ,GPIO_PinInput ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullDown  ,GPIO_INT_DEFAULT,GPIO_INT_DEFAULT,GPIO_INT_DEFAULT},
{GPIO_PinC1 ,GPIO_PinInput ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullDown  ,GPIO_INT_DEFAULT,GPIO_INT_DEFAULT,GPIO_INT_DEFAULT},
{GPIO_PinD0 ,GPIO_PinInput ,GPIO_PinDigital ,GPIO_Pin8mA ,GPIO_PinPullDown  ,GPIO_INT_ENABLED,GPIO_INT_EDGE   ,GPIO_INT_RISE   },

};

#endif
