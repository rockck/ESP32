#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h" // 添加 GPIO 驱动头文件

#define LED_GPIO GPIO_NUM_20 // 定义 LED 连接的 GPIO 引脚

void app_main(void)
{
    // 配置 GPIO 为输出模式
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;     // 禁用中断
    io_conf.mode = GPIO_MODE_OUTPUT;           // 设置为输出模式
    io_conf.pin_bit_mask = (1ULL << LED_GPIO); // 设置要配置的引脚
    io_conf.pull_down_en = 0;                  // 禁用下拉
    io_conf.pull_up_en = 0;                    // 禁用上拉
    gpio_config(&io_conf);                     // 应用配置

    printf("LED blinking on GPIO %d\n", LED_GPIO);

    while (1)
    {
        // 设置 GPIO 为高电平（点亮 LED）
        gpio_set_level(LED_GPIO, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS); // 延迟 500 毫秒

        // 设置 GPIO 为低电平（熄灭 LED）
        gpio_set_level(LED_GPIO, 0);
        vTaskDelay(500 / portTICK_PERIOD_MS); // 延迟 500 毫秒
    }
}