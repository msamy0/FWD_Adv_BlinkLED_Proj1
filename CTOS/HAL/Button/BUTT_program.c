#include "STD_Types.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "BUTT_interface.h"
#include "BUTT_config.h"


void HAL_BUTT_init(void)
{
	GPIO_init();
}

uint8 HAL_BUTT_Read(uint8 Button)
{
	return GPIO_ChannelRead(Button);
}
