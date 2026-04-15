#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pwm.h"
#include "motor.h"
#include "lcd.h"
#include "key.h"

uint8_t current_angle = 0 ;
uint8_t key_num = 0 ;
void app_main(void)
{
    lcd_init();
    key_init();
    pwm_init();
    
    set_angle(0);
    lcd_show_string(1,1,"angle:",GREEN,BLACK);
    while (1)
    {  
        key_num = key_scan();
        if(key_num == 1)
        {
            if(current_angle < 180)
            {
                current_angle += 45;
            }
            set_angle(current_angle);
        }
        else if(key_num == 2)
        {
            if(current_angle > 0)
            {
                current_angle -= 45;
            }
            set_angle(current_angle);
        }
        lcd_show_num(1,7,current_angle,3,YELLOW,BLACK);
        vTaskDelay(5);
    }
}