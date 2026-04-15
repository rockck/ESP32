#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "wifista.h"
#include "esp_sntp.h"
#include "mysntp.h"
#include <time.h>
#include "lcd.h"


void app_main(void)
{    
    nvs_flash_init();
    lcd_init();
    wifista_init();
    mysntp_init();

    time_t timer;
    struct tm * local_time;
    
    lcd_show_string(1,1,"Time:",GREEN,BLACK);
    lcd_show_string(2,1,"    .  .",YELLOW,BLACK);
    lcd_show_string(3,1,"  :  :",YELLOW,BLACK);
    
    while (1)
    {
        timer = time(NULL);
        local_time = localtime( &timer );

        lcd_show_num(2,1,local_time->tm_year+1900,4,YELLOW,BLACK);
        lcd_show_num(2,6,local_time->tm_mon+1,2,YELLOW,BLACK);
        lcd_show_num(2,9,local_time->tm_mday,2,YELLOW,BLACK);
        lcd_show_num(3,1,local_time->tm_hour,2,YELLOW,BLACK);
        lcd_show_num(3,4,local_time->tm_min,2,YELLOW,BLACK);
        lcd_show_num(3,7,local_time->tm_sec,2,YELLOW,BLACK);
        
        vTaskDelay(1000);
    }
}