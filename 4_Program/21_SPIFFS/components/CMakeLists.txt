set(src_dirs
            SPI
            LCD
            SPIFFS)

set(include_dirs
            SPI
            LCD
            SPIFFS)

set(requires
            vfs
            spiffs
            driver)

idf_component_register(SRC_DIRS ${src_dirs} INCLUDE_DIRS ${include_dirs} REQUIRES ${requires})

component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)