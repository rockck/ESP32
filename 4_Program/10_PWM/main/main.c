#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pwm.h"

void app_main(void)
{
    pwm_init();
    while (1)
    {
        for( uint16_t i = 0 ; i < 1000 ; i++ )
        {
            duty_set(i);
            vTaskDelay(1);
        }
        for( uint16_t i = 0 ; i < 1000 ; i++ )
        {
            duty_set(1000 - i);
            vTaskDelay(1);
        }
    }
}