#include "mysntp.h"
#include "esp_sntp.h"
#include <time.h>
#include "esp_log.h"
#include "lcd.h"

static const char * TAG = "MYSNTP";

void mysntp_init(void) 
{
    // 设置时间服务器（默认使用 pool.ntp.org）
    esp_sntp_setoperatingmode(SNTP_OPMODE_POLL);
    // 添加 NTP 服务器
    esp_sntp_setservername(0, "pool.ntp.org"); // 默认服务器
    esp_sntp_setservername(1, "cn.pool.ntp.org"); // 中国 NTP 服务器
    esp_sntp_setservername(2, "ntp1.aliyun.com"); //阿里云 NTP 服务器
    // 初始化 SNTP
    esp_sntp_init();
    // 设置时区（例如：北京时间 UTC+8）
    setenv("TZ", "CST-8", 1);
    tzset();
}

void print_current_time(void)
{
    time_t now;
    struct tm timeinfo;

   // 获取当前时间戳
    time(&now);
    // 将时间戳转换为本地时间
    localtime_r(&now, &timeinfo);
    // 使用 asctime 打印时间
    char *time_str = asctime(&timeinfo);
    if (time_str != NULL) 
    {
        // 去掉 asctime 输出的换行符
        time_str[strlen(time_str) - 1] = '\0';
        ESP_LOGI(TAG, "Current time: %s", time_str);
    } 
    else 
    {
        ESP_LOGE(TAG, "Failed to convert time to string");
    }
}