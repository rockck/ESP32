#include "oled.h"

static i2c_master_dev_handle_t oled_dev;
static uint8_t oled_buf[128 * 8 / 8];

static void oled_write_cmd(uint8_t cmd) {
    uint8_t data[2] = {0x00, cmd};
    i2c_master_transmit(oled_dev, data, 2, -1);
}

void oled_init(void) {
    i2c_master_bus_config_t bus_cfg = {
        .i2c_port = I2C_NUM_0,
        .sda_io_num = OLED_SDA_PIN,
        .scl_io_num = OLED_SCL_PIN,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
    };
    i2c_master_bus_handle_t bus_handle;
    i2c_new_master_bus(&bus_cfg, &bus_handle);

    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = OLED_I2C_ADDR,
        .scl_speed_hz = 400000,
    };
    i2c_master_bus_add_device(bus_handle, &dev_cfg, &oled_dev);

    vTaskDelay(pdMS_TO_TICKS(100));

    oled_write_cmd(0xAE);
    oled_write_cmd(0xD5);
    oled_write_cmd(0x80);
    oled_write_cmd(0xA8);
    oled_write_cmd(0x3F);
    oled_write_cmd(0xD3);
    oled_write_cmd(0x00);
    oled_write_cmd(0x40);
    oled_write_cmd(0x8D);
    oled_write_cmd(0x14);
    oled_write_cmd(0x20);
    oled_write_cmd(0x00);
    oled_write_cmd(0xA1);
    oled_write_cmd(0xC8);
    oled_write_cmd(0xDA);
    oled_write_cmd(0x12);
    oled_write_cmd(0x81);
    oled_write_cmd(0xCF);
    oled_write_cmd(0xD9);
    oled_write_cmd(0xF1);
    oled_write_cmd(0xDB);
    oled_write_cmd(0x30);
    oled_write_cmd(0xA4);
    oled_write_cmd(0xA6);
    oled_write_cmd(0xAF);

    oled_clear();
    oled_update();
}

void oled_clear(void) {
    for (int i = 0; i < sizeof(oled_buf); i++) {
        oled_buf[i] = 0x00;
    }
}

void oled_update(void) {
    for (uint8_t page = 0; page < 8; page++) {
        oled_write_cmd(0xB0 + page);
        oled_write_cmd(0x00);
        oled_write_cmd(0x10);

        uint8_t data[129];
        data[0] = 0x40;
        for (int i = 0; i < 128; i++) {
            data[i+1] = oled_buf[page * 128 + i];
        }
        i2c_master_transmit(oled_dev, data, 129, -1);
    }
}

void oled_show_string(uint8_t x, uint8_t y, const char *str) {
    (void)x; (void)y; (void)str;
}