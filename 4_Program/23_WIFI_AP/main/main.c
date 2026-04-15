#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "lcd.h"
#include "wifiap.h"
#include "nvs_flash.h"

void app_main(void)
{
    nvs_flash_init();
    lcd_init();
    wifiap_init();
    while (1)
    {
        vTaskDelay(500);
    }
}