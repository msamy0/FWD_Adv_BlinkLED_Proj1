/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    GPOI Private
* Module :      GPIO Module
* Description:  For private sections that are not accesed outside this module (Functions)
* REV:  				1.0
* DATE:					2023
* Autor: 				M. Samy
*
************************************************************************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/*- INCLUDES
------------------------------------------------------------------------------*/
#include "STD_Types.h"
#include "BIT_MATH.h"
#include <math.h>

/*- LOCAL MACROS
------------------------------------------------------------------------------*/
#define ARM_TM4C123GH6PM  1
#define ARM_APB           1

#define GPIO_ARM_APB_BaseABCD  0x40004000
#define GPIO_ARM_APB_BaseEF    0x40024000

#define GPIO_PortRead_InputErr 256

#define GPIO_PortOffset(PortName)         (PortName < 4 ? (GPIO_ARM_APB_BaseABCD + ((PortName) * 0x1000)) : (GPIO_ARM_APB_BaseEF + ((PortName-4) * 0x1000)) )

#define GPIO_DATA_Masked(PortName,Pin)	 *((volatile uint32*) (GPIO_PortOffset(PortName) + (((uint32)(pow(2,Pin)))<<2)) )
#define GPIO_DATA(PortName)              *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x3FC))

#define GPIO_DIR(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x400))
#define GPIO_IS(PortName)                *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x404))
#define GPIO_IBE(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x408))
#define GPIO_IEV(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x40C))
#define GPIO_IM(PortName)                *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x410))
#define GPIO_RIS(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x414))
#define GPIO_MIS(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x418))
#define GPIO_ICR(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x41C))
#define GPIO_AFSEL(PortName)             *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x420))
#define GPIO_DR2R(PortName)              *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x500))
#define GPIO_DR4R(PortName)              *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x504))
#define GPIO_DR8R(PortName)              *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x508))
#define GPIO_ODR(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x50C))
#define GPIO_PUR(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x510))
#define GPIO_PDR(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x514))
#define GPIO_SLR(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x518))
#define GPIO_DEN(PortName)               *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x51C))
#define GPIO_LOCK(PortName)              *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x520))
#define GPIO_CR(PortName)                *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x524))
#define GPIO_AMSEL(PortName)             *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x528))
#define GPIO_PCTL(PortName)              *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x52C))
#define GPIO_ADCCTL(PortName)            *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x530))
#define GPIO_DMACTL(PortName)            *((volatile uint32*) (GPIO_PortOffset(PortName) + 0x534))
#define GPIO_PeriphID4(PortName)         *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFD0))
#define GPIO_PeriphID5(PortName)         *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFD4))
#define GPIO_PeriphID6(PortName)         *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFD8))
#define GPIO_PeriphID7(PortName)         *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFDC))
#define GPIO_PeriphID0(PortName)         *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFE0))
#define GPIO_PeriphID1(PortName)         *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFE4))
#define GPIO_PeriphID2(PortName)         *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFE8))
#define GPIO_PeriphID3(PortName)         *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFEC))
#define GPIO_PCellID0(PortName)          *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFF0))
#define GPIO_PCellID1(PortName)          *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFF4))
#define GPIO_PCellID2(PortName)          *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFF8))
#define GPIO_PCellID3(PortName)          *((volatile uint32*) (GPIO_PortOffset(PortName) + 0xFFC))

#define SYS_RCGCGPIO                     *((volatile uint32*) (0x400FE608 ))

/*- LOCAL DATATYPES
------------------------------------------------------------------------------*/

typedef enum 
{
	GPIO_ReadLOW,
	GPIO_ReadHIGH,
	GPIO_SuccessfulOperation,
	GPIO_InputErr,
	GPIO_UnknownErr
} GPIO_ErrorHandlerType;


typedef enum
{	GPIO_PinA0, GPIO_PinA1, GPIO_PinA2, GPIO_PinA3, GPIO_PinA4, GPIO_PinA5, GPIO_PinA6, GPIO_PinA7,
	GPIO_PinB0, GPIO_PinB1, GPIO_PinB2, GPIO_PinB3, GPIO_PinB4, GPIO_PinB5, GPIO_PinB6, GPIO_PinB7,
	GPIO_PinC0, GPIO_PinC1, GPIO_PinC2, GPIO_PinC3, GPIO_PinC4, GPIO_PinC5, GPIO_PinC6, GPIO_PinC7,
	GPIO_PinD0, GPIO_PinD1, GPIO_PinD2, GPIO_PinD3, GPIO_PinD4, GPIO_PinD5, GPIO_PinD6, GPIO_PinD7,
	GPIO_PinE0, GPIO_PinE1, GPIO_PinE2, GPIO_PinE3, GPIO_PinE4, GPIO_PinE5, GPIO_PinE6, GPIO_PinE7,
	GPIO_PinF0, GPIO_PinF1, GPIO_PinF2, GPIO_PinF3, GPIO_PinF4, GPIO_PinF5, GPIO_PinF6, GPIO_PinF7
} GPIO_PinNameType;

typedef enum
{	GPIO_PortA,	GPIO_PortB, GPIO_PortC, GPIO_PortD, GPIO_PortE, GPIO_PortF
} GPIO_PortNameType;

typedef enum
{	GPIO_PinInput, GPIO_PinOutut
} GPIO_PinDirectionType;

typedef enum
{	GPIO_PinDigital, GPIO_PinAnalog
} GPIO_PinModeType;

typedef enum
{	GPIO_Pin2mA,GPIO_Pin4mA, GPIO_Pin8mA
} GPIO_PinOutCurrentType;

typedef enum
{	GPIO_PinPullUp,GPIO_PinPullDown
} GPIO_PinInternalAttachType;

typedef enum 
{
	GPIO_PinLOW, GPIO_PinHIGH
} GPIO_PinLevelType;


typedef struct
{	
	GPIO_PinNameType 				PinName;
	GPIO_PinDirectionType 			PinDirection;
	GPIO_PinModeType				PinMode;
	GPIO_PinOutCurrentType			PinOutputCurrent;
	GPIO_PinInternalAttachType		PinInternalAttach;
} GPIO_UserConfigStructType;
	
#endif

















