add_library(helper helper.c)

target_include_directories(helper
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)