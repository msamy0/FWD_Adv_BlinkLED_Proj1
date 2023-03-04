/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    NVIC private Lib
* Module :      NVIC Module
* Description: 	private resources for NVIC prephiral, Tiva C Hardware
* REV:  		1.0
* DATE:       
* AUTHOR:		M. Samy
************************************************************************************************************************/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/*- INCLUDES
------------------------------------------------------------------------------*/
#include "STD_Types.h"
#include "BIT_MATH.h"

/*- LOCAL MACROS
------------------------------------------------------------------------------*/
#define ARM_TM4C123GH6PM 1

#define NVIC_ARMBase  0xE000E000

#define NVIC_ENx(i)     (*((volatile uint32*) (NVIC_ARMBase + (0x100 + (i*0x04)))))
#define NVIC_DISx(i)    (*((volatile uint32*) (NVIC_ARMBase + (0x180 + (i*0x04)))))
#define NVIC_PRIx(i)    (*((volatile uint32*) (NVIC_ARMBase + (0x400 + (i*0x04)))))
#define NVIC_SYSPRIx(i) (*((volatile uint32*) (NVIC_ARMBase + (0xD18 + ((i-1)*0x04)))))
#define NVIC_PENDx(i)   (*((volatile uint32*) (NVIC_ARMBase + (0x200 + (i*0x04)))))
#define NVIC_UNPENDx(i) (*((volatile uint32*) (NVIC_ARMBase + (0x280 + (i*0x04)))))
#define NVIC_SWTRIG     (*((volatile uint32*) (NVIC_ARMBase +  0xF00            )))	
#define NVIC_APINT      (*((volatile uint32*) (NVIC_ARMBase +  0xD0C            )))	
#define NVIC_SYSHNDCTRL (*((volatile uint32*) (NVIC_ARMBase +  0xD24            )))	

/*- LOCAL DATATYPES
------------------------------------------------------------------------------*/
/* Enum for selecting enabling or disabling interrupts that are maskable */						
typedef enum {INT_DISABLED,
							INT_ENABLED ,
							NOT_ASSIGNED = 255
} NVIC_ENUM_EnableType;
							
/* Struct for User input data to configure NVIC prephiral */
typedef struct 
{
	NVIC_ENUM_EnableType 		EnableValue;
	uint8           		    GroupPriority;
	uint8             	     Advanced;
} NVIC_ConfigTableDatatype;


typedef enum 
{
Stack_0,
Reset_1,
NonMaskableInterr_2,
HardFault_3,
MemoryManageme_4,
BusFault_5,
UsageFault_6,
Reserved_7,
Reserved_8,
Reserved_9,
Reserved_10,
SVCall_11,
DebugMonitor_12,
Reserved_13,
PendSV_14,
SysTick_15,
GPIOPortA_16,
GPIOPortB_17,
GPIOPortC_18,
GPIOPortD_19,
GPIOPortE_20,
UART0_21,
UART1_22,
SSI0_23,
I2C0_24,
PWM0Fault_25,
PWM0Generator0_26,
PWM0Generator1_27,
PWM0Generator2_28,
QEI0_29,
ADC0Sequence0_30,
ADC0Sequence1_31,
ADC0Sequence2_32,
ADC0Sequence3_33,
WatchdogTimers01_34,
BitTimer_0A_35,
BitTimer0B_36,
BitTimer1A_37,
BitTimer1B_38,
BitTimer2A_39,
BitTimer2B_40,
AnalogComparator0_41,
AnalogComparator1_42,
Reserved_43,
SystemControl_44,
FlashMemoryCtrlEEPROMCtrl_45,
GPIOPortF_46,
Reserved_47,
Reserved_48,
UART2_49,
SSI1_50,
BitTimer3A_51,
BitTimer3B_52,
I2C1_53,
QEI1_54,
CAN0_55,
CAN1_56,
Reserved_57,
Reserved_58,
HibernationModule_59,
USB_60,
PWMGenerator3_61,
DMASoftware_62,
DMAError_63,
ADC1Sequence0_64,
ADC1Sequence1_65,
ADC1Sequence2_66,
ADC1Sequence3_67,
Reserved_68,
Reserved_69,
Reserved_70,
Reserved_71,
Reserved_72,
SSI2_73,
SSI3_74,
UART3_75,
UART4_76,
UART5_77,
UART6_78,
UART7_79,
Reserved_80,
Reserved_81,
Reserved_82,
Reserved_83,
I2C2_84,
I2C3_85,
BitTimer4A_86,
BitTimer4B_87,
Reserved_88,
Reserved_89,
Reserved_90,
Reserved_91,
Reserved_92,
Reserved_93,
Reserved_94,
Reserved_95,
Reserved_96,
Reserved_97,
Reserved_98,
Reserved_99,
Reserved_100,
Reserved_101,
Reserved_102,
Reserved_103,
Reserved_104,
Reserved_105,
Reserved_106,
Reserved_107,
BitTimer5A_108,
BitTimer5B_109,
BitTimer0A_110,
BitTimer0B_111,
BitTimer1A_112,
BitTimer1B_113,
BitTimer2A_114,
BitTimer2B_115,
BitTimer3A_116,
BitTimer3B_117,
BitTimer4A_118,
BitTimer4B_119,
BitTimer5A_120,
BitTimer5B_121,
SystemExceptionImp_122,
Reserved_123,
Reserved_124,
Reserved_125,
Reserved_126,
Reserved_127,
Reserved_128,
Reserved_129,
Reserved_130,
Reserved_131,
Reserved_132,
Reserved_133,
Reserved_134,
Reserved_135,
Reserved_136,
Reserved_137,
Reserved_138,
Reserved_139,
Reserved_140,
Reserved_141,
Reserved_142,
Reserved_143,
Reserved_144,
Reserved_145,
Reserved_146,
Reserved_147,
Reserved_148,
Reserved_149,
PWM1Generator0_150,
PWM1Generator1_151,
PWM1Generator2_152,
PWM1Generator3_153,
PWM1Fault_154
} NVIC_InterruptName;



#endif /* NVIC_PRIVATE_H_ */
