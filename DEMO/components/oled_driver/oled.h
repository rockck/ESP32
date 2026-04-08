#ifndef __OLED_H
#define __OLED_H

#include "driver/i2c_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdint.h>

#define OLED_SDA_PIN 4
#define OLED_SCL_PIN 5
#define OLED_I2C_ADDR 0x3C

void oled_init(void);
void oled_clear(void);
void oled_update(void);
void oled_show_string(uint8_t x, uint8_t y, const char *str);

#endif