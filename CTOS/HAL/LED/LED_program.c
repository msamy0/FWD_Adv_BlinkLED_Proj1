#include "STD_Types.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"

void HAL_LED_init(void)
{
	GPIO_init();
}

void HAL_LED_ON(uint8 LED)
{
	GPIO_ChannelWrite(LED,GPIO_PinHIGH );
}
void HAL_LED_OFF(uint8 LED)
{
	GPIO_ChannelWrite(LED,GPIO_PinLOW );
}
void HAL_LED_TOG(uint8 LED)
{
	GPIO_ChannelToggle(LED);
}
