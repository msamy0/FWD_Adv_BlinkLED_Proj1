/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    NVIC Configuration
* Module :      NVIC Module
* Description: 	For driver user to config NVIC module depending on target and application
* REV:  				1.0
* DATE:
* AUTHOR:       M. Samy
*
************************************************************************************************************************/
#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_

#include "NVIC_private.h"

/* Select ARM Based Target [ARM_TM4C123GH6PM , To be Continued...]*/
#define NVIC_Target ARM_TM4C123GH6PM

/* Select Grouping scheme for NVIC 
 * ARM_TM4C123GH6PM -> G8_S0(0x04) , G4_S2(0x05) , G2_S4(0x06) , G0_S8(0x07)
 * STM32            -> To be continued...
 */
#define NVIC_PriorityGrouping    0x04

/* Error handling */
#if NVIC_Target == 0
	#error "NVIC driver have no proper target, kindly select one !"
#else
	#if NVIC_Target == ARM_TM4C123GH6PM
		#define NVIC_INT_QTY   155
	#endif
	#if NVIC_Target == ARM_TM4C123GH6PM && (NVIC_PriorityGrouping < 0x04 || NVIC_PriorityGrouping > 0x07)
		#error "Kindly, select prober NVIC grouping" 
	#endif 
#endif

static const NVIC_ConfigTableDatatype NVIC_ConfigTableUserInput[NVIC_INT_QTY] =
{
/*
{Enable      ,Priority    ,Advanced (for future upgrades)} */	
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 0 Stack */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 1 Reset */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 2 Non-Maskable Interrupt */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 3 Hard Fault */

{INT_DISABLED,0           ,0           }, /* 4 Memory Management */
{INT_DISABLED,0           ,0           }, /* 5 Bus Fault */
{INT_DISABLED,0           ,0           }, /* 6 Usage Fault */

{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 7 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 8 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 9 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 10 Reserved */

{NOT_ASSIGNED,0           ,0           }, /* 11 SVCall */
{NOT_ASSIGNED,0           ,0           }, /* 12 Debug Monitor */

{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 13 Reserved */

{NOT_ASSIGNED,0           ,0           }, /* 14 PendSV */
{NOT_ASSIGNED,0           ,0           }, /* 15 SysTick */
{INT_DISABLED,0           ,0           }, /* 16 GPIO Port A */
{INT_DISABLED,0           ,0           }, /* 17 GPIO Port B */
{INT_DISABLED,0           ,0           }, /* 18 GPIO Port C */
{INT_DISABLED,0           ,0           }, /* 19 GPIO Port D */
{INT_DISABLED,0           ,0           }, /* 20 GPIO Port E */
{INT_DISABLED,0           ,0           }, /* 21 UART0 */
{INT_DISABLED,0           ,0           }, /* 22 UART1 */
{INT_DISABLED,0           ,0           }, /* 23 SSI0 */
{INT_DISABLED,0           ,0           }, /* 24 I2C0 */
{INT_DISABLED,0           ,0           }, /* 25 PWM0 Fault */
{INT_DISABLED,0           ,0           }, /* 26 PWM0 Generator 0 */
{INT_DISABLED,0           ,0           }, /* 27 PWM0 Generator 1 */
{INT_DISABLED,0           ,0           }, /* 28 PWM0 Generator 2 */
{INT_DISABLED,0           ,0           }, /* 29 QEI0 */
{INT_DISABLED,0           ,0           }, /* 30 ADC0 Sequence 0 */
{INT_DISABLED,0           ,0           }, /* 31 ADC0 Sequence 1 */
{INT_DISABLED,0           ,0           }, /* 32 ADC0 Sequence 2 */
{INT_DISABLED,0           ,0           }, /* 33 ADC0 Sequence 3 */
{INT_DISABLED,0           ,0           }, /* 34 Watchdog Timers 0 and 1 */
{INT_DISABLED,0           ,0           }, /* 35 16/32-Bit Timer 0A */
{INT_DISABLED,0           ,0           }, /* 36 16/32-Bit Timer 0B */
{INT_DISABLED,0           ,0           }, /* 37 16/32-Bit Timer 1A */
{INT_DISABLED,0           ,0           }, /* 38 16/32-Bit Timer 1B */
{INT_DISABLED,0           ,0           }, /* 39 16/32-Bit Timer 2A */
{INT_DISABLED,0           ,0           }, /* 40 16/32-Bit Timer 2B */
{INT_DISABLED,0           ,0           }, /* 41 Analog Comparator 0 */
{INT_DISABLED,0           ,0           }, /* 42 Analog Comparator 1 */

{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 43 Reserved */

{INT_DISABLED,0           ,0           }, /* 44 System Control */
{INT_DISABLED,0           ,0           }, /* 45 Flash Memory Control and EEPROM Control */
{INT_DISABLED,0           ,0           }, /* 46 GPIO Port F */

{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 47 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 48 Reserved */

{INT_DISABLED,0           ,0           }, /* 49 UART2 */
{INT_DISABLED,0           ,0           }, /* 50 SSI1 */
{INT_DISABLED,0           ,0           }, /* 51 16/32-Bit Timer 3A */
{INT_DISABLED,0           ,0           }, /* 52 16/32-Bit Timer 3B */
{INT_DISABLED,0           ,0           }, /* 53 I2C1 */
{INT_DISABLED,0           ,0           }, /* 54 QEI1 */
{INT_DISABLED,0           ,0           }, /* 55 CAN0 */
{INT_DISABLED,0           ,0           }, /* 56 CAN1 */

{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 57 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 58 Reserved */

{INT_DISABLED,0           ,0           }, /* 59 Hibernation Module */
{INT_DISABLED,0           ,0           }, /* 60 USB */
{INT_DISABLED,0           ,0           }, /* 61 PWM Generator 3 */
{INT_DISABLED,0           ,0           }, /* 62 uDMA Software */
{INT_DISABLED,0           ,0           }, /* 63 uDMA Error */
{INT_DISABLED,0           ,0           }, /* 64 ADC1 Sequence 0 */
{INT_DISABLED,0           ,0           }, /* 65 ADC1 Sequence 1 */
{INT_DISABLED,0           ,0           }, /* 66 ADC1 Sequence 2 */
{INT_DISABLED,0           ,0           }, /* 67 ADC1 Sequence 3 */

{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 68 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 69 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 70 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 71 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 72 Reserved */

{INT_DISABLED,0           ,0           }, /* 73 SSI2 */
{INT_DISABLED,0           ,0           }, /* 74 SSI3 */
{INT_DISABLED,0           ,0           }, /* 75 UART3 */
{INT_DISABLED,0           ,0           }, /* 76 UART4 */
{INT_DISABLED,0           ,0           }, /* 77 UART5 */
{INT_DISABLED,0           ,0           }, /* 78 UART6 */
{INT_DISABLED,0           ,0           }, /* 79 UART7 */

{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 80 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 81 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 82 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 83 Reserved */

{INT_DISABLED,0           ,0           }, /* 84 I2C2 */
{INT_DISABLED,0           ,0           }, /* 85 I2C3 */
{INT_DISABLED,0           ,0           }, /* 86 16/32-Bit Timer 4A */
{INT_DISABLED,0           ,0           }, /* 87 16/32-Bit Timer 4B */

{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 88 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 89 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 90 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 91 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 92 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 93 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 94 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 95 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 96 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 97 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 98 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 99 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 100 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 101 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 102 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 103 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 104 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 105 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 106 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 107 Reserved */

{INT_DISABLED,0           ,0           }, /* 108 16/32-Bit Timer 5A */
{INT_DISABLED,0           ,0           }, /* 109 16/32-Bit Timer 5B */
{INT_DISABLED,0           ,0           }, /* 110 32/64-Bit Timer 0A */
{INT_DISABLED,0           ,0           }, /* 111 32/64-Bit Timer 0B */
{INT_DISABLED,0           ,0           }, /* 112 32/64-Bit Timer 1A */
{INT_DISABLED,0           ,0           }, /* 113 32/64-Bit Timer 1B */
{INT_DISABLED,0           ,0           }, /* 114 32/64-Bit Timer 2A */
{INT_DISABLED,0           ,0           }, /* 115 32/64-Bit Timer 2B */
{INT_DISABLED,0           ,0           }, /* 116 32/64-Bit Timer 3A */
{INT_DISABLED,0           ,0           }, /* 117 32/64-Bit Timer 3B */
{INT_DISABLED,0           ,0           }, /* 118 32/64-Bit Timer 4A */
{INT_DISABLED,0           ,0           }, /* 119 32/64-Bit Timer 4B */
{INT_DISABLED,0           ,0           }, /* 120 32/64-Bit Timer 5A */
{INT_DISABLED,0           ,0           }, /* 121 32/64-Bit Timer 5B */
{INT_DISABLED,0           ,0           }, /* 122 System Exception (imprecise) */

{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 123 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 124 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 125 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 126 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 127 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 128 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 129 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 130 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 131 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 132 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 133 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 134 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 135 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 136 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 137 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 138 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 139 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 140 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 141 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 142 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 143 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 144 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 145 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 146 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 147 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 148 Reserved */
{NOT_ASSIGNED,NOT_ASSIGNED,NOT_ASSIGNED}, /* 149 Reserved */

{INT_DISABLED,0           ,0           }, /* 150 PWM1 Generator 0 */
{INT_DISABLED,0           ,0           }, /* 151 PWM1 Generator 1 */
{INT_DISABLED,0           ,0           }, /* 152 PWM1 Generator 2 */
{INT_DISABLED,0           ,0           }, /* 153 PWM1 Generator 3 */
{INT_DISABLED,0           ,0           }  /* 154 PWM1 Fault */
};

#endif
