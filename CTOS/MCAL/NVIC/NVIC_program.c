/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    NVIC program
* Module :      NVIC Module
* Description: 	Functions and APIs for NVIC prephiral, Tiva C Hardware
* REV:  				1.0
* DATE:       	
*
************************************************************************************************************************/
/*- INCLUDES
------------------------------------------------------------------------------*/
#include "BIT_MATH.h"
#include "STD_Types.h"

#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"

/*- GLOBAL STATIC VARIABLES
------------------------------------------------------------------------------*/
static uint8 NVIC_ConfigTableSize = sizeof(NVIC_ConfigTableUserInput)/sizeof(NVIC_ConfigTableUserInput[0]);
static const uint8 NVIC_ReservedI[] = {0,7,8,9,10,13,43,47,48,57,58,68,69,70,71,72,80,81,82,83,
                                      88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,
                                      123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,
                                      140,141,142,143,144,145,146,147,148,149};

/*- LOCAL FUNCTIONS PROTOTYPES
------------------------------------------------------------------------------*/
static STD_DriverErrHandlerType NVIC_SetIntPriority(uint8, NVIC_InterruptNameType);
static STD_DriverErrHandlerType NVIC_EnableInt(NVIC_InterruptNameType);
static STD_DriverErrHandlerType NVIC_DisableInt(NVIC_InterruptNameType);

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------------------------------------------------------------*/

/* Setting the priority scheme for exceptions in Cortex M4*/
static STD_DriverErrHandlerType NVIC_SetPriorityGroup(uint8 u8PriorityShceme)
{
	if (u8PriorityShceme < 4 || u8PriorityShceme > 7)
	{
		return NOK;
	}
	
	else
	{
	NVIC_APINT |= ((uint32)u8PriorityShceme <<8);
	return OK;
	}
}

/* Set priority of each interrupt*/
static STD_DriverErrHandlerType NVIC_SetIntPriority(uint8 u8Priority, NVIC_InterruptNameType u8_Interrupt)
{
	/* ToDo: To be optimized using binary search*/
	for (uint8 u8LocalCounter=0 ; u8LocalCounter < sizeof(NVIC_ReservedI)/sizeof(NVIC_ReservedI[0]) ; u8LocalCounter++)
	{
		if (u8_Interrupt ==NVIC_ReservedI[u8LocalCounter])
			return NOK;
	}

	if (u8Priority == INT_DEFAULT)
	{
		return OK;
	}
	else
	{
		if (u8_Interrupt >= 16) /* Interrupt Type (Not System Exception) */
		{

			u8_Interrupt -= 16;
			
			uint8 u8LocalRegSelector 	= (uint8)( ((float)u8_Interrupt) / 4.00 );
			uint8 u8LocalIntOrder 		= u8_Interrupt - (u8LocalRegSelector*4);
			u8LocalIntOrder 		    = (u8LocalIntOrder*8) + 5; // Bit position in PRI Reg
			
			/* Cast u8Priority to uint32 
			 * then shift them to the left to be in position of required interrupt
			 * then mask all other pins to keep the original register values
			 * then AND result with PRI Register 
			 * Priority = 0b00000(101) ->  0b00...(101)00000 -> 0b11...(101)11111 -> AND with PRIx
			*/
			NVIC_PRIx(u8LocalRegSelector) &= ( (((uint32)u8Priority) << u8LocalIntOrder) | 0xFFF8 );
			
			return OK;
			
		}
		
		else /* Memory - Bus - Usage - Debug - PendSV - SysTick - SVCall */
		{
			
			switch (u8_Interrupt)
			{
				case 4: // Memory
					NVIC_SYSPRIx(1) &= ( (((uint32)u8Priority) << 5) | 0xFFF8 );
					return OK;
				
				case 5: // Bus
					NVIC_SYSPRIx(1) &= ( (((uint32)u8Priority) << 13) | 0xFFF8 );
					return OK;
				
				case 6: // Usage Fault
					NVIC_SYSPRIx(1) &= ( (((uint32)u8Priority) << 21) | 0xFFF8 );
					return OK;
				
				case 11: // SVCall
					NVIC_SYSPRIx(2) &= ( (((uint32)u8Priority) << 29) | 0xFFF8 );
					return OK;
				
				case 12: // Debug
					NVIC_SYSPRIx(3) &= ( (((uint32)u8Priority) << 5) | 0xFFF8 );
					return OK;
				
				case 14: // PendSV
					NVIC_SYSPRIx(3) &= ( (((uint32)u8Priority) << 21) | 0xFFF8 );
					return OK;
				
				case 15: // SysTick
					NVIC_SYSPRIx(3) &= ( (((uint32)u8Priority) << 29) | 0xFFF8 );
					return OK;
				
				default:
					return NOK;
			}

		}
	}
}



static STD_DriverErrHandlerType NVIC_EnableInt(NVIC_InterruptNameType u8_Interrupt)
{
	for (uint8 u8LocalCounter=0 ; u8LocalCounter < sizeof(NVIC_ReservedI)/sizeof(NVIC_ReservedI[0]) ; u8LocalCounter++)
	{
		if (u8_Interrupt ==NVIC_ReservedI[u8LocalCounter])
			return NOK;
	}

	if (u8_Interrupt == INT_DEFAULT)
	{
		return OK;
	}
	
	else if (u8_Interrupt == INT_NOT_ASSIGNED)
	{
		return NOK;
	}

	else
	{
		if (u8_Interrupt >= 16) /* Interrupt Type (Not System Exception) */
		{
			u8_Interrupt -= 16;
			
			uint8 u8LocalRegSelector 	= (uint8)( (float)(((float)u8_Interrupt) / 32.00) );
			uint8 u8LocalIntOrder 		= u8_Interrupt - (u8LocalRegSelector*32);
			
			SET_BIT(NVIC_ENx(u8LocalRegSelector),u8LocalIntOrder);
			
			return OK;
			
		}
		
		else /* Memory - Bus - Usage */
		{
			switch (u8_Interrupt)
			{
				case 4: // Memory
					SET_BIT(NVIC_SYSHNDCTRL,16);
					return OK;
				
				case 5: // Bus
					SET_BIT(NVIC_SYSHNDCTRL,17);
					return OK;

				case 6: // Usage Fault
					SET_BIT(NVIC_SYSHNDCTRL,18);
					return OK;

				default:
					return NOK;
			}

		}	

	}	
}

static STD_DriverErrHandlerType NVIC_DisableInt(NVIC_InterruptNameType u8_Interrupt)
{
	for (uint8 u8LocalCounter=0 ; u8LocalCounter < sizeof(NVIC_ReservedI)/sizeof(NVIC_ReservedI[0]) ; u8LocalCounter++)
	{
		if (u8_Interrupt ==NVIC_ReservedI[u8LocalCounter])
			return NOK;
	}
	
	if (u8_Interrupt == INT_NOT_ASSIGNED)
	{
		return NOK;
	}

	else
	{
		if (u8_Interrupt >= 16) /* Interrupt Type (Not System Exception) */
		{
			u8_Interrupt -= 16;
			
			uint8 u8LocalRegSelector 	= (uint8)( (float)(((float)u8_Interrupt) / 32.00) );
			uint8 u8LocalIntOrder 		= u8_Interrupt - (u8LocalRegSelector*32);
			
			SET_BIT(NVIC_DISx(u8LocalRegSelector),u8LocalIntOrder);
			
			return OK;
			
		}
		
		else /* Memory - Bus - Usage */
		{
			switch (u8_Interrupt)
			{
				case 4: // Memory
					CLEAR_BIT(NVIC_SYSHNDCTRL,16);
					return OK;
				
				case 5: // Bus
					CLEAR_BIT(NVIC_SYSHNDCTRL,17);
					return OK;

				case 6: // Usage Fault
					CLEAR_BIT(NVIC_SYSHNDCTRL,18);
					return OK;

				default:
					return NOK;
			}

		}	

	}	

}

/*- APIS IMPLEMENTATION
------------------------------------------------------------------------------*/


STD_DriverErrHandlerType NVIC_Init(void)
{
	if (NVIC_ConfigTableSize == 0)
	{
		return NOK;
	}
	
	if (NVIC_SetPriorityGroup(NVIC_PriorityGrouping) != OK)
	{
		return NOK;
	}
	
	for (uint8 u8LocalCounterA = 0 ; u8LocalCounterA < NVIC_ConfigTableSize ; u8LocalCounterA++)
	{
		
		NVIC_SetIntPriority(NVIC_ConfigTableUserInput[u8LocalCounterA].Priority,NVIC_ConfigTableUserInput[u8LocalCounterA].Name);

		if (NVIC_ConfigTableUserInput[u8LocalCounterA].EnableValue == INT_ENABLED)
			NVIC_EnableInt(NVIC_ConfigTableUserInput[u8LocalCounterA].Name);
		
		else if (NVIC_ConfigTableUserInput[u8LocalCounterA].EnableValue == INT_DISABLED)
			NVIC_DisableInt(u8LocalCounterA);

	}
	
	return OK;
}

	
