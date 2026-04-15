#include "ffs.h"

void spiffs_init(void)
{
    esp_vfs_spiffs_conf_t  spiffs_structure = {
        .base_path = SPIFFS_BASE_PATH,
        .format_if_mount_failed = true,
        .max_files = 2,
        .partition_label = NULL,
    };
    esp_vfs_spiffs_register(&spiffs_structure);
}