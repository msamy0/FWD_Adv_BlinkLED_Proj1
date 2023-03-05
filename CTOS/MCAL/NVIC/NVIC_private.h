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
				INT_ENABLED,
				INT_DEFAULT = 254,
				INT_NOT_ASSIGNED = 255
} NVIC_ENUM_EnableType;

/*  */
typedef enum {
INT_FALL,
INT_RISE,
INT_BOTH,

} NVIC_ENUM_EventType;

typedef enum {
INT_EDGE,
INT_LEVEL,

} NVIC_ENUM_LevelType;
							

typedef enum 
{
INT_Name_BusFault_5                   =5,
INT_Name_UsageFault_6                 =6,
INT_Name_SVCall_11                    =11,
INT_Name_DebugMonitor_12              =12,
INT_Name_PendSV_14                    =14,
INT_Name_SysTick_15                   =15,
INT_Name_GPIOPortA_16                 =16,
INT_Name_GPIOPortB_17                 =17,
INT_Name_GPIOPortC_18                 =18,
INT_Name_GPIOPortD_19                 =19,
INT_Name_GPIOPortE_20                 =20,
INT_Name_UART0_21                     =21,
INT_Name_UART1_22                     =22,
INT_Name_SSI0_23                      =23,
INT_Name_I2C0_24                      =24,
INT_Name_PWM0Fault_25                 =25,
INT_Name_PWM0Generator0_26            =26,
INT_Name_PWM0Generator1_27            =27,
INT_Name_PWM0Generator2_28            =28,
INT_Name_QEI0_29                      =29,
INT_Name_ADC0Sequence0_30             =30,
INT_Name_ADC0Sequence1_31             =31,
INT_Name_ADC0Sequence2_32             =32,
INT_Name_ADC0Sequence3_33             =33,
INT_Name_WatchdogTimers01_34          =34,
INT_Name_BitTimer_0A_35               =35,
INT_Name_BitTimer0B_36                =36,
INT_Name_BitTimer1A_37                =37,
INT_Name_BitTimer1B_38                =38,
INT_Name_BitTimer2A_39                =39,
INT_Name_BitTimer2B_40                =40,
INT_Name_AnalogComparator0_41         =41,
INT_Name_AnalogComparator1_42         =42,
INT_Name_SystemControl_44             =44,
INT_Name_FlashMemoryCtrlEEPROMCtrl_45 =45,
INT_Name_GPIOPortF_46                 =46,
INT_Name_UART2_49                     =49,
INT_Name_SSI1_50                      =50,
INT_Name_BitTimer3A_51                =51,
INT_Name_BitTimer3B_52                =52,
INT_Name_I2C1_53                      =53,
INT_Name_QEI1_54                      =54,
INT_Name_CAN0_55                      =55,
INT_Name_CAN1_56                      =56,
INT_Name_HibernationModule_59         =59,
INT_Name_USB_60                       =60,
INT_Name_PWMGenerator3_61             =61,
INT_Name_DMASoftware_62               =62,
INT_Name_DMAError_63                  =63,
INT_Name_ADC1Sequence0_64             =64,
INT_Name_ADC1Sequence1_65             =65,
INT_Name_ADC1Sequence2_66             =66,
INT_Name_ADC1Sequence3_67             =67,
INT_Name_SSI2_73                      =73,
INT_Name_SSI3_74                      =74,
INT_Name_UART3_75                     =75,
INT_Name_UART4_76                     =76,
INT_Name_UART5_77                     =77,
INT_Name_UART6_78                     =78,
INT_Name_UART7_79                     =79,
INT_Name_Reserved_80                  =80,
INT_Name_Reserved_81                  =81,
INT_Name_Reserved_82                  =82,
INT_Name_Reserved_83                  =83,
INT_Name_I2C2_84                      =84,
INT_Name_I2C3_85                      =85,
INT_Name_BitTimer4A_86                =86,
INT_Name_BitTimer4B_87                =87,
INT_Name_BitTimer5A_108               =108,
INT_Name_BitTimer5B_109               =109,
INT_Name_BitTimer0A_110               =110,
INT_Name_BitTimer0B_111               =111,
INT_Name_BitTimer1A_112               =112,
INT_Name_BitTimer1B_113               =113,
INT_Name_BitTimer2A_114               =114,
INT_Name_BitTimer2B_115               =115,
INT_Name_BitTimer3A_116               =116,
INT_Name_BitTimer3B_117               =117,
INT_Name_BitTimer4A_118               =118,
INT_Name_BitTimer4B_119               =119,
INT_Name_BitTimer5A_120               =120,
INT_Name_BitTimer5B_121               =121,
INT_Name_SystemExceptionImp_122       =122,
INT_Name_PWM1Generator0_150           =150,
INT_Name_PWM1Generator1_151           =151,
INT_Name_PWM1Generator2_152           =152,
INT_Name_PWM1Generator3_153           =153,
INT_Name_PWM1Fault_154                =154,
} NVIC_InterruptNameType;

/* Struct for User input data to configure NVIC prephiral */
typedef struct
{
	NVIC_InterruptNameType			Name;
	NVIC_ENUM_EnableType 		    EnableValue;
	uint8           		        Priority;
	NVIC_ENUM_EventType				Event;
	NVIC_ENUM_LevelType				Level;


} NVIC_ConfigTableDatatype;

#endif /* NVIC_PRIVATE_H_ */
