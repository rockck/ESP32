#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_partition.h"
#include "lcd.h"

#define USER_PARTITION_TYPE    0x40
#define USER_PARTITION_SUBTYPE 0x01
const char *string = "PartitionTest!";
const esp_partition_t*   partition_ptr = NULL;

void app_main(void)
{
    lcd_init();

    partition_ptr = esp_partition_find_first(USER_PARTITION_TYPE,USER_PARTITION_SUBTYPE, NULL);

    esp_partition_erase_range(partition_ptr,0, 0x1000);
    esp_partition_write(partition_ptr,0, string, strlen(string));

    char read_buf[64];
    memset(read_buf,0,sizeof(read_buf));
    esp_partition_read(partition_ptr,0, read_buf, strlen(string));

    lcd_show_string(1,1,read_buf,YELLOW,BLACK);

    return;
}