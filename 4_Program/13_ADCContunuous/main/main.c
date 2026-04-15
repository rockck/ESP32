#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "myadc.h"
#include "lcd.h"


void app_main(void)
{
    lcd_init();
    adc_init();

    lcd_show_string(1,1,"adc1:",GREEN,BLACK);
    lcd_show_string(2,1,"adc2:",GREEN,BLACK);
    while (1)
    {
        lcd_show_num(1,6,adc_value_rp,4,YELLOW,BLACK);
        lcd_show_num(2,6,adc_value_rl,4,YELLOW,BLACK);
        vTaskDelay(500);
    }
}