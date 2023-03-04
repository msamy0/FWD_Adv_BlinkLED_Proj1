/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    GPOI Implementation file
* Module :      GPIO Module
* Description:  Implementation of Functions and APIs
* REV:  		1.0
* DATE:			2023
* Autor: M. Samy
*
************************************************************************************************************************/

/*- INCLUDES
------------------------------------------------------------------------------*/
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"


/*- LOCAL FUNCTION PROTOTYPES
------------------------------------------------------------------------------*/


/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------------------------------------------------------------*/

/*- APIS IMPLEMENTATION
------------------------------------------------------------------------------*/
GPIO_ErrorHandlerType GPIO_ChannelDirectionSet(GPIO_PinNameType GPIO_PinName, GPIO_PinDirectionType GPIO_PinDir)
{
	if(GPIO_PinName < GPIO_PinA0 || GPIO_PinName > GPIO_PinF7 || GPIO_PinDir < GPIO_PinInput || GPIO_PinDir > GPIO_PinOutut)
	{
		return GPIO_InputErr;
	}
	else
	{
		/*Get the Pin index by degrading it until reaching 0-7 index
		Get Port of the selecting pin by counting number of degrading*/
		GPIO_PortNameType  GPIO_PortName = GPIO_PortA;
		while (GPIO_PinName >7)
		{
			GPIO_PinName-=8;
			GPIO_PortName++;
		}
		switch (GPIO_PinDir)
		{
			case GPIO_PinOutut:
				SET_BIT(GPIO_DIR(GPIO_PortName),GPIO_PinName);
			break;

			case GPIO_PinInput:
				CLEAR_BIT(GPIO_DIR(GPIO_PortName),GPIO_PinName);
			break;
		}
		return GPIO_SuccessfulOperation;
	}
}

GPIO_ErrorHandlerType GPIO_ChannelRead(GPIO_PinNameType GPIO_PinName)
{
	if(GPIO_PinName < GPIO_PinA0 || GPIO_PinName > GPIO_PinF7)
	{
		return GPIO_InputErr;
	}
	else
	{
		/*Get the Pin index by degrading it until reaching 0-7 index
		Get Port of the selecting pin by counting number of degrading*/
		GPIO_PortNameType  GPIO_PortName = GPIO_PortA;
		while (GPIO_PinName >7)
		{
			GPIO_PinName-=8;
			GPIO_PortName++;
		}
		return GET_BIT(GPIO_DATA(GPIO_PortName),GPIO_PinName);
	}
}
/*
GPIO_ErrorHandlerType GPIO_AtomicChannelRead(GPIO_PinNameType GPIO_PinName)
{
	if(GPIO_PinName < 0 || GPIO_PinName > 47)
	{
		return GPIO_InputErr;
	}
	else
	{
		if (GPIO_PinName <= GPIO_PinA7)
		{
			return (GPIO_DATA_Masked(GPIO_PortA,(GPIO_PinName - GPIO_PortA_PinShifter)))>>(GPIO_PinName - GPIO_PortA_PinShifter);
		}

		else if (GPIO_PinName > GPIO_PinA7 && GPIO_PinName <= GPIO_PinB7)
		{
			return (GPIO_DATA_Masked(GPIO_PortB,(GPIO_PinName - GPIO_PortB_PinShifter)))>>(GPIO_PinName - GPIO_PortB_PinShifter);
		}

		else if (GPIO_PinName > GPIO_PinB7 && GPIO_PinName <= GPIO_PinC7)
		{
			return (GPIO_DATA_Masked(GPIO_PortC,(GPIO_PinName - GPIO_PortC_PinShifter)))>>(GPIO_PinName - GPIO_PortC_PinShifter);
		}

		else if (GPIO_PinName > GPIO_PinC7 && GPIO_PinName <= GPIO_PinD7)
		{
			return (GPIO_DATA_Masked(GPIO_PortD,(GPIO_PinName - GPIO_PortD_PinShifter)))>>(GPIO_PinName - GPIO_PortD_PinShifter);
		}

		else if (GPIO_PinName > GPIO_PinD7 && GPIO_PinName <= GPIO_PinE7)
		{
			return (GPIO_DATA_Masked(GPIO_PortE,(GPIO_PinName - GPIO_PortE_PinShifter)))>>(GPIO_PinName - GPIO_PortE_PinShifter);
		}

		else if (GPIO_PinName > GPIO_PinE7 && GPIO_PinName <= GPIO_PinF7)
		{
			return (GPIO_DATA_Masked(GPIO_PortF,(GPIO_PinName - GPIO_PortF_PinShifter)))>>(GPIO_PinName - GPIO_PortF_PinShifter);
		}

		else
		{
			return GPIO_UnknownErr;
		}
	}
}
*/

GPIO_ErrorHandlerType  GPIO_ChannelWrite(GPIO_PinNameType GPIO_PinName, GPIO_PinLevelType GPIO_PinLvl)
{
	if(GPIO_PinName < GPIO_PinA0 || GPIO_PinName > GPIO_PinF7 || GPIO_PinLvl < GPIO_PinLOW || GPIO_PinLvl > GPIO_PinHIGH)
	{
		return GPIO_InputErr;
	}
	else
	{
		/* Get the Pin index by degrading it until reaching 0-7 index
		 * Get Port of the selecting pin by counting number of degrading*/
		GPIO_PortNameType  GPIO_PortName = GPIO_PortA;
		while (GPIO_PinName >7)
		{
			GPIO_PinName-=8;
			GPIO_PortName++;
		}

		switch (GPIO_PinLvl)
		{
			case GPIO_PinHIGH:
				SET_BIT(GPIO_DATA(GPIO_PortName),GPIO_PinName);
			break;

			case GPIO_PinLOW:
				CLEAR_BIT(GPIO_DATA(GPIO_PortName),GPIO_PinName);
			break;
		}
		return GPIO_SuccessfulOperation;
	}
}
/*
GPIO_ErrorHandlerType GPIO_AtomicChannelWrite(GPIO_PinNameType GPIO_PinName, GPIO_PinLevelType GPIO_PinLvl)
{
	if(GPIO_PinName < 0 || GPIO_PinName > 47 || GPIO_PinLvl < 0 || GPIO_PinLvl > 1)
	{
		return GPIO_InputErr;
	}
	else
	{
		switch (GPIO_PinLvl)
		{
			case GPIO_PinHIGH:
				if (GPIO_PinName <= GPIO_PinA7)
				{
					GPIO_DATA_Masked(GPIO_PortA,(GPIO_PinName - GPIO_PortA_PinShifter) ) = 0xFFFFFFFF;
				}

				else if (GPIO_PinName > GPIO_PinA7 && GPIO_PinName <= GPIO_PinB7)
				{
					GPIO_DATA_Masked(GPIO_PortB,(GPIO_PinName - GPIO_PortB_PinShifter) ) = 0xFFFFFFFF;
				}

				else if (GPIO_PinName > GPIO_PinB7 && GPIO_PinName <= GPIO_PinC7)
				{
					GPIO_DATA_Masked(GPIO_PortC,(GPIO_PinName - GPIO_PortC_PinShifter) ) = 0xFFFFFFFF;
				}

				else if (GPIO_PinName > GPIO_PinC7 && GPIO_PinName <= GPIO_PinD7)
				{
					GPIO_DATA_Masked(GPIO_PortD,(GPIO_PinName - GPIO_PortD_PinShifter) ) = 0xFFFFFFFF;
				}

				else if (GPIO_PinName > GPIO_PinD7 && GPIO_PinName <= GPIO_PinE7)
				{
					GPIO_DATA_Masked(GPIO_PortE,(GPIO_PinName - GPIO_PortE_PinShifter) ) = 0xFFFFFFFF;
				}

				else if (GPIO_PinName > GPIO_PinE7 && GPIO_PinName <= GPIO_PinF7)
				{
					GPIO_DATA_Masked(GPIO_PortF,(GPIO_PinName - GPIO_PortF_PinShifter) ) = 0xFFFFFFFF;
				}
			break;

			case GPIO_PinLOW:
				if (GPIO_PinName <= GPIO_PinA7)
				{
					GPIO_DATA_Masked(GPIO_PortA,(GPIO_PinName - GPIO_PortA_PinShifter) ) = 0x00000000;
				}

				else if (GPIO_PinName > GPIO_PinA7 && GPIO_PinName <= GPIO_PinB7)
				{
					GPIO_DATA_Masked(GPIO_PortB,(GPIO_PinName - GPIO_PortB_PinShifter) ) = 0x00000000;
				}

				else if (GPIO_PinName > GPIO_PinB7 && GPIO_PinName <= GPIO_PinC7)
				{
					GPIO_DATA_Masked(GPIO_PortC,(GPIO_PinName - GPIO_PortC_PinShifter) ) = 0x00000000;
				}

				else if (GPIO_PinName > GPIO_PinC7 && GPIO_PinName <= GPIO_PinD7)
				{
					GPIO_DATA_Masked(GPIO_PortD,(GPIO_PinName - GPIO_PortD_PinShifter) ) = 0x00000000;
				}

				else if (GPIO_PinName > GPIO_PinD7 && GPIO_PinName <= GPIO_PinE7)
				{
					GPIO_DATA_Masked(GPIO_PortE,(GPIO_PinName - GPIO_PortE_PinShifter) ) = 0x00000000;
				}

				else if (GPIO_PinName > GPIO_PinE7 && GPIO_PinName <= GPIO_PinF7)
				{
					GPIO_DATA_Masked(GPIO_PortF,(GPIO_PinName - GPIO_PortF_PinShifter) ) = 0x00000000;
				}
			break;
		}
		return GPIO_SuccessfulOperation;
	}
}
*/

GPIO_ErrorHandlerType GPIO_ChannelToggle(GPIO_PinNameType GPIO_PinName)
{
	if(GPIO_PinName < GPIO_PinA0 || GPIO_PinName > GPIO_PinF7)
	{
		return GPIO_InputErr;
	}
	else
	{
		/* Get the Pin index by degrading it until reaching 0-7 index
		 * Get Port of the selecting pin by counting number of degrading*/
		GPIO_PortNameType  GPIO_PortName = GPIO_PortA;
		while (GPIO_PinName >7)
		{
			GPIO_PinName-=8;
			GPIO_PortName++;
		}
		TOGGLE_BIT(GPIO_DATA(GPIO_PortName),GPIO_PinName);
		return GPIO_SuccessfulOperation;
	}
}

uint16 GPIO_PortRead(GPIO_PortNameType GPIO_PortName)
{
	if(GPIO_PortName < GPIO_PortA || GPIO_PortName > GPIO_PortF)
	{
		return GPIO_PortRead_InputErr;
	}
	else
	{
		return GPIO_DATA(GPIO_PortName);
	}
}

GPIO_ErrorHandlerType GPIO_PortWrite(GPIO_PortNameType GPIO_PortName, uint8 u8LocalPortLevel)
{
	if (GPIO_PortName < GPIO_PortA || GPIO_PortName > GPIO_PortF )
	{
		return GPIO_InputErr;
	}
	else
	{
		GPIO_DATA(GPIO_PortName) = u8LocalPortLevel;
		return GPIO_SuccessfulOperation;
	}
}

GPIO_ErrorHandlerType GPIO_PortClockSet(GPIO_PinNameType GPIO_PinName)
{
	if(GPIO_PinName < GPIO_PinA0 || GPIO_PinName > GPIO_PinF7)
	{
		return GPIO_InputErr;
	}
	else
	{
		GPIO_PortNameType  GPIO_PortName = GPIO_PortA;
		while (GPIO_PinName >7)
		{
			GPIO_PinName-=8;
			GPIO_PortName++;
		}
		SET_BIT(SYS_RCGCGPIO,GPIO_PortName);
		return GPIO_SuccessfulOperation;
	}
}

GPIO_ErrorHandlerType GPIO_ChannelMode(GPIO_PinNameType GPIO_PinName, GPIO_PinModeType GPIO_PinMode)
{
	if(GPIO_PinName < GPIO_PinA0 || GPIO_PinName > GPIO_PinF7 || GPIO_PinMode < GPIO_PinDigital || GPIO_PinMode > GPIO_PinAnalog)
	{
		return GPIO_InputErr;
	}
	else
	{
		/* Get the Pin index by degrading it until reaching 0-7 index
		 * Get Port of the selecting pin by counting number of degrading*/
		GPIO_PortNameType  GPIO_PortName = GPIO_PortA;
		while (GPIO_PinName >7)
		{
			GPIO_PinName-=8;
			GPIO_PortName++;
		}
		switch (GPIO_PinMode)
		{
			case GPIO_PinDigital:
				SET_BIT(GPIO_DEN(GPIO_PortName),GPIO_PinName);
			break;

			case GPIO_PinAnalog:
				SET_BIT(GPIO_AMSEL(GPIO_PortName),GPIO_PinName);
			break;
	    }
		return GPIO_SuccessfulOperation;
	}
}

GPIO_ErrorHandlerType GPIO_ChannelAttach(GPIO_PinNameType GPIO_PinName, GPIO_PinInternalAttachType GPIO_PinAttach)
{
	if(GPIO_PinName < GPIO_PinA0 || GPIO_PinName > GPIO_PinF7 || GPIO_PinAttach < GPIO_PinPullUp || GPIO_PinAttach > GPIO_PinPullDown)
	{
		return GPIO_InputErr;
	}
	else
	{
		/* Get the Pin index by degrading it until reaching 0-7 index
		 * Get Port of the selecting pin by counting number of degrading*/
		GPIO_PortNameType  GPIO_PortName = GPIO_PortA;
		while (GPIO_PinName >7)
		{
			GPIO_PinName-=8;
			GPIO_PortName++;
		}
		switch (GPIO_PinAttach)
				{
					case GPIO_PinPullUp:
						SET_BIT(GPIO_PUR(GPIO_PortName),GPIO_PinName);
					break;

					case GPIO_PinPullDown:
						SET_BIT(GPIO_PDR(GPIO_PortName),GPIO_PinName);
					break;
			    }
		return GPIO_SuccessfulOperation;
	}
}

GPIO_ErrorHandlerType GPIO_init(void)
{
	uint8 u8ConfigTableSize = sizeof(GPIO_ConfigTableUserInput)/sizeof(GPIO_ConfigTableUserInput[0]);
	if (u8ConfigTableSize > ((uint8)GPIO_PinF7 + 1))
	{
		return GPIO_InputErr ;
	}
	for (uint8 u8LocalCounter =0 ; u8LocalCounter < u8ConfigTableSize ; u8LocalCounter++)
	{
		GPIO_PortClockSet		(GPIO_ConfigTableUserInput[u8LocalCounter].PinName);
		GPIO_ChannelDirectionSet(GPIO_ConfigTableUserInput[u8LocalCounter].PinName, GPIO_ConfigTableUserInput[u8LocalCounter].PinDirection);
		GPIO_ChannelMode        (GPIO_ConfigTableUserInput[u8LocalCounter].PinName, GPIO_ConfigTableUserInput[u8LocalCounter].PinMode);
		GPIO_ChannelAttach      (GPIO_ConfigTableUserInput[u8LocalCounter].PinName, GPIO_ConfigTableUserInput[u8LocalCounter].PinInternalAttach);
		/* ToDo :- Set Current by adding API accessing it*/
	}
	return GPIO_SuccessfulOperation;
}



