#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "lcd.h"
#include "spi_sdcard.h"
#include "math.h"
#include "exfuns.h"
#include "ff.h"
#include "esp_log.h"

static const char * TAG = "MAIN";
FIL fnew;																						
UINT fnum;
uint8_t ReadBuffer[115200];

void app_main(void)
{
    uint8_t image_cnt = 0 ;
    lcd_init();
    while (sd_spi_init())                               /* 检测不到SD卡 */
    {
        ESP_LOGE(TAG,"SDCard init error!\r\n");
        vTaskDelay(1000);
    }

    exfuns_init(); 

    while (1)
    {
        image_cnt++;
        switch (image_cnt)
        {
            case 1:
                f_open(&fnew, "0:image1.bin",FA_READ);
                f_read(&fnew, ReadBuffer, sizeof(ReadBuffer), &fnum);
                f_close(&fnew);
                break;
            case 2:
                f_open(&fnew, "0:image2.bin",FA_READ);
                f_read(&fnew, ReadBuffer, sizeof(ReadBuffer), &fnum);
                f_close(&fnew);
                break;
            case 3:
                f_open(&fnew, "0:image3.bin",FA_READ);
                f_read(&fnew, ReadBuffer, sizeof(ReadBuffer), &fnum);
                f_close(&fnew);
                break;
            case 4:
                f_open(&fnew, "0:image4.bin",FA_READ);
                f_read(&fnew, ReadBuffer, sizeof(ReadBuffer), &fnum);
                f_close(&fnew);
                break;
            case 5:
                f_open(&fnew, "0:image5.bin",FA_READ);
                f_read(&fnew, ReadBuffer, sizeof(ReadBuffer), &fnum);
                f_close(&fnew);
                break;
            case 6:
                f_open(&fnew, "0:image6.bin",FA_READ);
                f_read(&fnew, ReadBuffer, sizeof(ReadBuffer), &fnum);
                f_close(&fnew);
                image_cnt = 0 ;
                break;
            default:
                break;
        }
        lcd_show_picture(ReadBuffer);
        vTaskDelay(10);
    }
}