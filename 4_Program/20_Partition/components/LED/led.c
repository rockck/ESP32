#include "led.h"

void led_init(void)
{
    gpio_config_t gpio_structure = {0};
    gpio_structure.intr_type = GPIO_INTR_DISABLE;
    gpio_structure.mode =  GPIO_MODE_INPUT_OUTPUT ;
    gpio_structure.pin_bit_mask = 1ull << GPIO_NUM_38 ;
    gpio_structure.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_structure.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&gpio_structure);
}

void gpio_toggle(gpio_num_t gpio_num)
{
	if( gpio_get_level( gpio_num ) == 1 )
	{
		gpio_set_level(gpio_num, 0);
	}
	else
	{
		gpio_set_level(gpio_num, 1);
	}
}