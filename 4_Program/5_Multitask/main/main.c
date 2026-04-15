#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "led.h"
#include "key.h"

void led_task(void* param)
{
     uint8_t key_num = 0 ;
     while(1)
     {
         key_num = key_scan();
          if(key_num == 1)
          {
               gpio_toggle(GPIO_NUM_39);
          } 
          vTaskDelay(5);
     }
}

void key_task(void *param)
{
     while (1)
     {
          gpio_toggle(GPIO_NUM_38);
          vTaskDelay(100);
     }
}

void app_main(void)
{
    led_init();
    key_init();

    xTaskCreatePinnedToCore(led_task,"led_task",1024,NULL,1,NULL,0);
    xTaskCreatePinnedToCore(key_task,"key_task",1024,NULL,2,NULL,0);
}