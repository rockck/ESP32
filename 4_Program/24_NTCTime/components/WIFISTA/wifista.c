#include "wifista.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_event.h"

static const char * TAG = "WIFISTA";

void wifista_event_handler(void* event_handler_arg,esp_event_base_t event_base,int32_t event_id,void* event_data)
{
    static int reconnect_cnt = 0;
    if(event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
    {
        esp_wifi_connect();
        ESP_LOGI(TAG,"wifi sta start success!\r\n");
    }
    else if(event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_CONNECTED)
    {
        ESP_LOGI(TAG,"wifi sta connect success!\r\n");
    }
    else if(event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        if(reconnect_cnt < 10)
        {
            esp_wifi_connect();
            reconnect_cnt++;
            ESP_LOGI(TAG,"wifi sta reconnect = %d\r\n",reconnect_cnt);
        }
        else
        {
            reconnect_cnt = 0 ;
            esp_wifi_stop();
            esp_wifi_deinit();
            ESP_LOGI(TAG,"wifi sta close!\r\n");
        }
    }
    else if(event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG,"ip="IPSTR,IP2STR(&event->ip_info.ip));
    }
}

void wifista_init(void)
{
    esp_netif_init();
    esp_event_loop_create_default();
    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID,&wifista_event_handler, NULL);
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &wifista_event_handler, NULL);
    esp_netif_create_default_wifi_sta();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);
    esp_wifi_set_mode(WIFI_MODE_STA);
    wifi_config_t  wifi_config = {
        .sta = {
            .ssid = DEFAULT_SSID,
            .password = DEFAULT_PWD
        }
    };
    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    esp_wifi_start();
}