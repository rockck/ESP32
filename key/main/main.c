#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "led.h"
#include "key.h"

void app_main(void)
{
    uint8_t key_num = 0 ;
    led_init();
    key_init();

    while (1)
    {
        key_num = key_scan();
        if(key_num == 1)
        {
             gpio_toggle(GPIO_NUM_38);
        }
        else if(key_num == 2)
        {
             gpio_toggle(GPIO_NUM_39);
        }
        else if(key_num == 3)
        {
             gpio_toggle(GPIO_NUM_41);
        }
        else if(key_num == 4)
        {
             gpio_toggle(GPIO_NUM_42);
        }
        vTaskDelay(5);
    }
}