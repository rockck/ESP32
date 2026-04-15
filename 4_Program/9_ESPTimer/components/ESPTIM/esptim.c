#include "esptim.h"
#include "driver/gpio.h"
#include "esp_timer.h"
#include "led.h"
#include "lcd.h"

uint16_t timer_cnt = 0 ;

void esptimer_callback(void *param)
{
    timer_cnt++;
    lcd_show_num(1,5,timer_cnt,4,YELLOW,BLACK);
    gpio_toggle(GPIO_NUM_38);
}

void esptimer_init(void)
{
    esp_timer_handle_t esptimer = NULL;
    esp_timer_create_args_t esptimer_structure = {
        .callback = &esptimer_callback,
        .arg = NULL,
    };
    esp_timer_create(&esptimer_structure,&esptimer);

    esp_timer_start_periodic(esptimer, 500000);         
}

