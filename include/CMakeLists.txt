add_library(rFileHandler rFileHandler.c)

target_include_directories(rFileHandler
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)