#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "bh1750.h"
#include "lcd.h"

float light = 0 ;

void app_main(void)
{
    lcd_init();
    bh1750_init();
    
    lcd_show_string(1,1,"light:",GREEN,BLACK);
    while (1)
    {
        light = bh1750_read_data() / 1.2;
        lcd_show_float(1,7,light,6,YELLOW,BLACK);
        vTaskDelay(1000);
    }
}