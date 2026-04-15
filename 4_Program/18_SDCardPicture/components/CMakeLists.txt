set(src_dirs
            SDIO
            SPI
            LCD
            LED)

set(include_dirs
            SDIO
            SPI
            LCD
            LED)

set(requires
            fatfs
            driver)

idf_component_register(SRC_DIRS ${src_dirs} INCLUDE_DIRS ${include_dirs} REQUIRES ${requires})

component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)