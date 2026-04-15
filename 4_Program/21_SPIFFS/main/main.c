#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "ffs.h"
#include "lcd.h"

const char *test_string = "SPIFFS_Test!";
char read_buf[64];

void app_main(void)
{
    lcd_init();
    spiffs_init();
    lcd_show_string(1,1,"read_buf:",GREEN,BLACK);

    FILE* f = fopen("/spiffs/test.txt", "w");
    fprintf(f, test_string);
    fclose(f);

    vTaskDelay(1000);

    f =fopen("/spiffs/test.txt", "r");
    fgets(read_buf,sizeof(read_buf),f);
    fclose(f);

    lcd_show_string(2,1,read_buf,YELLOW,BLACK);

    return;
}