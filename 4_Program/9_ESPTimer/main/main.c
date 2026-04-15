#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esptim.h"
#include "led.h"
#include "lcd.h"

void app_main(void)
{
    lcd_init();
    led_init();
    esptimer_init();
    lcd_show_string(1,1,"CNT:",GREEN,BLACK);
    while (1)
    {
        vTaskDelay(5);
    }
}