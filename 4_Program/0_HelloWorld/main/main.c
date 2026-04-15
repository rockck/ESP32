#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char * TAG1 = "INFO";
static const char * TAG2 = "ERR";

void app_main(void)
{
    while (1)
    {
        printf("This is printf!\r\n");
        ESP_LOGI(TAG1,"This is an information!\r\n");
        ESP_LOGE(TAG2,"This is an error!\r\n");
        vTaskDelay(500);
    }
}