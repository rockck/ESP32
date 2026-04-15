set(src_dirs
            SPI
            LCD
            MYADC)

set(include_dirs
            SPI
            LCD
            MYADC)

set(requires
            esp_adc
            driver)

idf_component_register(SRC_DIRS ${src_dirs} INCLUDE_DIRS ${include_dirs} REQUIRES ${requires})

component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)