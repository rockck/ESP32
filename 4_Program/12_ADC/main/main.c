#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "myadc.h"
#include "lcd.h"

int adc1_value = 0 ;
int adc2_value = 0 ;

void app_main(void)
{
    lcd_init();
    adc_init();

    lcd_show_string(1,1,"adc1:",GREEN,BLACK);
    lcd_show_string(2,1,"adc2:",GREEN,BLACK);
    while (1)
    {
        adc_oneshot_read(adc_unit_handle, ADC_CHANNEL_3, &adc1_value);
        adc_oneshot_read(adc_unit_handle, ADC_CHANNEL_4, &adc2_value);
        lcd_show_num(1,6,adc1_value,4,YELLOW,BLACK);
        lcd_show_num(2,6,adc2_value,4,YELLOW,BLACK);
        vTaskDelay(500);
    }
}