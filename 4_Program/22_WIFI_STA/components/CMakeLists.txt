set(src_dirs
            WIFISTA
            LCD
            SPI
            LED)

set(include_dirs
            WIFISTA
            LCD
            SPI
            LED)

set(requires
            esp_wifi
            driver)

idf_component_register(SRC_DIRS ${src_dirs} INCLUDE_DIRS ${include_dirs} REQUIRES ${requires})

component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)