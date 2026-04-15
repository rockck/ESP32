#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "lcd.h"
#include "wifista.h"
#include "nvs_flash.h"


void app_main(void)
{
    nvs_flash_init();
    lcd_init();
    wifista_init();
    while (1)
    {
        vTaskDelay(500);
    }
}