#include "key.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void key_init(void)
{
    gpio_config_t gpio_cfg = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_INPUT,
        .pin_bit_mask = (1 << GPIO_NUM_9),
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
    };
    gpio_config(&gpio_cfg);
}

uint8_t key_scan(void)
{
    uint8_t key_num = 0;
    if (gpio_get_level(GPIO_NUM_9) == 0)
    {
        vtaskdelay(20);
        while (gpio_get_level(GPIO_NUM_9) == 0)
            vtaskdelay(20);
        key_num = 1;
    }
    if (gpio_get_level(GPIO_NUM_10) == 0)
    {
        vtaskdelay(20);
        while (gpio_get_level(GPIO_NUM_10) == 0)
            vtaskdelay(20);
        key_num = 2;
    }
    if (gpio_get_level(GPIO_NUM_11) == 0)
    {
        vtaskdelay(20);
        while (gpio_get_level(GPIO_NUM_11) == 0)
            vtaskdelay(20);
        key_num = 3;
    }
    if (gpio_get_level(GPIO_NUM_12) == 0)
    {
        vtaskdelay(20);
        while (gpio_get_level(GPIO_NUM_12) == 0)
            vtaskdelay(20);
        key_num = 4;
    }
    return key_num;
}
