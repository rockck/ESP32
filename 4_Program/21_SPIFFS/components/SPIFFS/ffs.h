#ifndef __MYFFS_H_
#define __MYFFS_H_

#include "esp_spiffs.h"
#include "esp_vfs.h"

#define SPIFFS_BASE_PATH   "/spiffs"

void spiffs_init(void);

#endif
