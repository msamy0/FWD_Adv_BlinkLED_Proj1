#include "STD_Types.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "BUTT_interface.h"
#include "LED_interface.h"


void App_SysTick_Callback(void* CBAptr)
{
	HAL_LED_TOG( *((GPIO_PinNameType*)CBAptr) );
}

void App_GPIO_D_Callback(void* CBAptr)
{
	HAL_LED_TOG( *((GPIO_PinNameType*)CBAptr) );
}


void App_Setup(void)
{
	HAL_LED_init();
	HAL_BUTT_init();
	SysTick_init();
	NVIC_Init();

	static GPIO_PinNameType SysTick_CBArgument = GPIO_PinF1;
	SysTick_CallbackRegister(App_SysTick_Callback,(void*)(&SysTick_CBArgument));

	static GPIO_PinNameType GPIO_D_CBArgument = GPIO_PinF2;
	GPIO_D_CallbackRegister(App_GPIO_D_Callback, (void*)(&GPIO_D_CBArgument));

	SysTick_EnableDisable(STICK_Enable);
}

void App_Run(void)
{
	uint8 button1_flag = 0;
	uint8 endOfUserInput_flag = 0;
	uint32 UserTimerValue = 0;
	uint32 MillisInHundreds=0;
	while(1)
	{
		endOfUserInput_flag = 0;

		/* System will start listen on button 1 press*/
		while(HAL_BUTT_Read(BUTTON_1))
		{
			if (HAL_BUTT_Read(BUTTON_2))
			{
				for (uint8 i=0 ; i < 100 ; i++);
				if ( !(HAL_BUTT_Read(BUTTON_2)) )
				{
					MillisInHundreds++;
				}
			}
			endOfUserInput_flag = 1;
		}

		/* System will override systick value on change*/
		if (endOfUserInput_flag == 1 && MillisInHundreds > 0)
		{
			SysTick_SetReloadMillis((uint32)(MillisInHundreds *100));
			MillisInHundreds = 0;
		}
	}
}
