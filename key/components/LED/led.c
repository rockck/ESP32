#include "led.h"
#include "driver/gpio.h"

void led_init(void)
{
    gpio_config_t gpio_structure = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_INPUT_OUTPUT,
        .pin_bit_mask = (1ull<<GPIO_NUM_38)|(1ull<<GPIO_NUM_39)|(1ull<<GPIO_NUM_41)|(1ull<<GPIO_NUM_42),
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_ENABLE,
    };
    gpio_config(&gpio_structure);
    
    gpio_set_level(GPIO_NUM_38,1);
    gpio_set_level(GPIO_NUM_39,1);
    gpio_set_level(GPIO_NUM_41,1);
    gpio_set_level(GPIO_NUM_42,1);
}

void gpio_toggle(gpio_num_t gpio_num)
{
    if(gpio_get_level(gpio_num) == 1)
    {
        gpio_set_level(gpio_num,0);
    }
    else
    {
        gpio_set_level(gpio_num,1);
    }
}