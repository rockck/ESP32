#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"

void app_main(void)
{
    led_init();
    while (1)
    {
        gpio_toggle(GPIO_NUM_38);
        vTaskDelay(500);
    }
}