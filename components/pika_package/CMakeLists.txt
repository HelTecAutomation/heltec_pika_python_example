
file(GLOB_RECURSE SOURCES *.c)
idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS 
                    "pikascript-api"
                    "pikascript-core"
                    "pikascript-lib/PikaStdLib"
                    "pikascript-lib/ESP32"
                    "pikascript-lib/PikaStdDevice"
                    "pikascript-lib/time"
                    "../../main"
                    WHOLE_ARCHIVE
                    REQUIRES driver esp_wifi nvs_flash 
                    
                    )
