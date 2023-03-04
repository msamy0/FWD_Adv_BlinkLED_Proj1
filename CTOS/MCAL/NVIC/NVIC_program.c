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


/*- LOCAL FUNCTIONS PROTOTYPES
------------------------------------------------------------------------------*/
static STD_DriverErrHandlerType NVIC_SetPriorityGroup(uint8);
static STD_DriverErrHandlerType NVIC_SetIntPriority(uint8, NVIC_InterruptName);
static STD_DriverErrHandlerType NVIC_EnableInt(NVIC_InterruptName);
static STD_DriverErrHandlerType NVIC_DisableInt(NVIC_InterruptName);

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------------------------------------------------------------*/

/* Setting the priority scheme for exceptions in Cortex M4*/
static STD_DriverErrHandlerType NVIC_SetPriorityGroup(uint8 u8PriorityShceme)
{
	if (u8PriorityShceme < 0x04 || u8PriorityShceme > 0x07)
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
static STD_DriverErrHandlerType NVIC_SetIntPriority(uint8 u8Priority, NVIC_InterruptName u8_Interrupt)
{
	if (u8_Interrupt > NVIC_INT_QTY -1)
	{
		return NOK;
	}
	
	else if (NVIC_ConfigTableUserInput [u8_Interrupt].GroupPriority == NOT_ASSIGNED)
	{
		return NOK;
	}
	
	else
	{
		if (u8_Interrupt >= 0x16) /* Interrupt Type (Not System Exception) */
		{
			u8_Interrupt -= 16;
			
			uint8 u8LocalRegSelector 	= (uint8)( ((float)u8_Interrupt) / 4L );
			uint8 u8LocalIntOrder 		= u8_Interrupt - (u8LocalRegSelector*4);
			u8LocalIntOrder 					= (u8LocalIntOrder*8) + 5; // Bit position in PRI Reg
			
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
				case 0x04: // Memory
					NVIC_SYSPRIx(1) &= ( (((uint32)u8Priority) << 5) | 0xFFF8 );
					return OK;
				
				case 0x05: // Bus
					NVIC_SYSPRIx(1) &= ( (((uint32)u8Priority) << 13) | 0xFFF8 );
					return OK;
				
				case 0x06: // Usage Fault
					NVIC_SYSPRIx(1) &= ( (((uint32)u8Priority) << 21) | 0xFFF8 );
					return OK;
				
				case 0x11: // SVCall
					NVIC_SYSPRIx(2) &= ( (((uint32)u8Priority) << 29) | 0xFFF8 );
					return OK;
				
				case 0x12: // Debug
					NVIC_SYSPRIx(3) &= ( (((uint32)u8Priority) << 5) | 0xFFF8 );
					return OK;
				
				case 0x14: // PendSV
					NVIC_SYSPRIx(3) &= ( (((uint32)u8Priority) << 21) | 0xFFF8 );
					return OK;
				
				case 0x15: // SysTick
					NVIC_SYSPRIx(3) &= ( (((uint32)u8Priority) << 29) | 0xFFF8 );
					return OK;
				
				default:
					return NOK;
			}

		}
	}
}



static STD_DriverErrHandlerType NVIC_EnableInt(NVIC_InterruptName u8_Interrupt)
{
	if (u8_Interrupt > NVIC_INT_QTY -1)
	{
		return NOK;
	}
	
	else if (NVIC_ConfigTableUserInput [u8_Interrupt].GroupPriority == NOT_ASSIGNED)
	{
		return NOK;
	}

	else
	{
		if (u8_Interrupt >= 0x16) /* Interrupt Type (Not System Exception) */
		{
			u8_Interrupt -= 16;
			
			uint8 u8LocalRegSelector 	= (uint8)( ((float)u8_Interrupt) / 32L );
			uint8 u8LocalIntOrder 		= u8_Interrupt - (u8LocalRegSelector*32);
			
			SET_BIT(NVIC_ENx(u8LocalRegSelector),u8LocalIntOrder);
			
			return OK;
			
		}
		
		else /* Memory - Bus - Usage */
		{
			switch (u8_Interrupt)
			{
				case 0x04: // Memory
					SET_BIT(NVIC_SYSHNDCTRL,16);
					return OK;
				
				case 0x05: // Bus
					SET_BIT(NVIC_SYSHNDCTRL,17);
					return OK;

				case 0x06: // Usage Fault
					SET_BIT(NVIC_SYSHNDCTRL,18);
					return OK;

				default:
					return NOK;
			}

		}	

	}	
}

static STD_DriverErrHandlerType NVIC_DisableInt(NVIC_InterruptName u8_Interrupt)
{
		if (u8_Interrupt > NVIC_INT_QTY -1)
	{
		return NOK;
	}
	
	else if (NVIC_ConfigTableUserInput [u8_Interrupt].GroupPriority == NOT_ASSIGNED)
	{
		return NOK;
	}

	else
	{
		if (u8_Interrupt >= 0x16) /* Interrupt Type (Not System Exception) */
		{
			u8_Interrupt -= 16;
			
			uint8 u8LocalRegSelector 	= (uint8)( ((float)u8_Interrupt) / 32L );
			uint8 u8LocalIntOrder 		= u8_Interrupt - (u8LocalRegSelector*32);
			
			SET_BIT(NVIC_DISx(u8LocalRegSelector),u8LocalIntOrder);
			
			return OK;
			
		}
		
		else /* Memory - Bus - Usage */
		{
			switch (u8_Interrupt)
			{
				case 0x04: // Memory
					CLEAR_BIT(NVIC_SYSHNDCTRL,16);
					return OK;
				
				case 0x05: // Bus
					CLEAR_BIT(NVIC_SYSHNDCTRL,17);
					return OK;

				case 0x06: // Usage Fault
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
STD_DriverErrHandlerType NVIC_Init(void)
{
	if (sizeof(NVIC_ConfigTableUserInput) == 0)
	{
		return NOK;
	}
	
	if (NVIC_SetPriorityGroup(NVIC_PriorityGrouping) != OK)
	{
		return NOK;
	}
	
	for (uint8 u8LocalCounterA = 4 ; u8LocalCounterA < NVIC_INT_QTY ; u8LocalCounterA++)
	{
		if(NVIC_ConfigTableUserInput[u8LocalCounterA].GroupPriority == NOT_ASSIGNED)
		{
			continue;
		}
		else
		{
			NVIC_SetIntPriority(NVIC_ConfigTableUserInput[u8LocalCounterA].GroupPriority, u8LocalCounterA);
		}
		
		if (NVIC_ConfigTableUserInput[u8LocalCounterA].EnableValue == INT_ENABLED )
		{
			NVIC_EnableInt(u8LocalCounterA);
		}
		
		else if (NVIC_ConfigTableUserInput[u8LocalCounterA].EnableValue == INT_DISABLED )
		{
			NVIC_DisableInt(u8LocalCounterA);
		}	
	}
	
	return OK;
}

	
