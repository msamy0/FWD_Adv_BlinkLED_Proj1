/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    SysTick Configuration
* Module :      SysTick Module
* Description:  For compile configuration of Systick Module
* REV:  		1.0
* DATE:			2023
* Autor: M. Samy
*
************************************************************************************************************************/
#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

/*- INCLUDES
------------------------------------------------------------------------------*/


//Comment or un-comment for SysTick Usage
#define STICK_UseSysTick
#ifdef STICK_UseSysTick

//Comment or un-comment for Interrupt usage
#define STICK_UseInterrupt

// Select InternalClock or SystemClock
#define STICK_ClockSource    SystemClock

//Specify the Oscillator  frequency in MHz
#define STICK_CPUFreq 12000000UL

//Specify the initial Reload Value
#define STICK_initReloadvalue 10000UL
#if STICK_initReloadvalue > 0xFFFFFF
#error " Initial STICK_Reloadvalue must be less than or equal (16777215UL MHz) to fit into 24-bit register"
#endif

#endif


#endif // SYSTICK_CONFIG_H_
