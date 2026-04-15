#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "led.h"
#include "beep.h"

void app_main(void)
{
    beep_init();
    while (1)
    {
        gpio_toggle(GPIO_NUM_41);
        vTaskDelay(500);
    }
}