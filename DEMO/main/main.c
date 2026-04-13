#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"
#include "key.h"
void app_main(void)
{
    led_init();
    key_init();
    uint8_t key_num = 0;

    while (1)
    {
        // gpio_toggle(GPIO_NUM_2);
        // vTaskDelay(500);
        key_num = key_scan();
        if (key_num == 1)
        {

            gpio_toggle(GPIO_NUM_2);
        }
        else if (key_num == 2)
        {

            gpio_toggle(GPIO_NUM_4);
        }
        else if (key_num == 3)
        {

            gpio_toggle(GPIO_NUM_5);
        }
        else if (key_num == 4)
        {

            gpio_toggle(GPIO_NUM_6);
        }
    }
}