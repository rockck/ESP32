#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "oled.h"
#include "driver/gpio.h"

#define LED_GPIO 20     // LED 接 GPIO20
#define OLED_DC_PIN 21  // 必须显式定义 OLED 引脚
#define OLED_RST_PIN 22 // 根据实际接线修改

void app_main(void)
{
    oled_init();
    gpio_config_t io_conf = {0};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << OLED_DC_PIN) | (1ULL << OLED_RST_PIN) | (1ULL << LED_GPIO);
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);

    while (1)
    {
        gpio_set_level(LED_GPIO, 1); // 开灯
        oled_clear();
        oled_show_string(0, 0, "HELLO ESP32S3");
        oled_update();
        vTaskDelay(pdMS_TO_TICKS(500));

        gpio_set_level(LED_GPIO, 0); // 关灯
        oled_clear();
        oled_show_string(0, 0, "HELLO ESP32S3");
        oled_update();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}