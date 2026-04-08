#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "oled.h" // 必须包含

void app_main(void)
{
    // 初始化OLED（小写！）
    oled_init();

    while (1)
    {
        // 清屏
        oled_clear();

        // 显示字符串（x, y, 内容）
        oled_show_string(0, 0, "HELLO ESP32S3");

        // 更新屏幕
        oled_update();

        // 延时1秒
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}