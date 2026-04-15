#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "led.h"
#include "beep.h"
#include "usart.h"

void app_main(void)
{
    uint8_t length = 0 ;
    uint8_t receive_data[1024] = {0};
    led_init();
    beep_init();
    uart_init();
    while (1)
    {
        length = uart_read_bytes(UART_NUM_1, receive_data, 1024, 100);
        if(length > 0)
        {
            if(receive_data[0] == 0x5A && receive_data[length - 1] == 0xA5)
            {
                if(receive_data[1] == 0x00)
                {
                    gpio_set_level(GPIO_NUM_38,1);
                }
                else if(receive_data[1] == 0x01)
                {
                    gpio_set_level(GPIO_NUM_38,0);
                }
                if(receive_data[2] == 0x00)
                {
                    gpio_set_level(GPIO_NUM_47,1);
                }
                else if(receive_data[2] == 0x01)
                {
                    gpio_set_level(GPIO_NUM_47,0);
                }
            }
            uart_flush(UART_NUM_1);
        }
    }
}