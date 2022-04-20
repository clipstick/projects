add_library(usermod_pico_display INTERFACE)

target_sources(usermod_pico_display INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/pico_display.c
    ${CMAKE_CURRENT_LIST_DIR}/pico_display.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../../libraries/pico_display/pico_display.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../../drivers/st7789/st7789.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../../libraries/pico_graphics/pico_graphics.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../../libraries/pico_graphics/types.cpp
)

target_include_directories(usermod_pico_display INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_definitions(usermod_pico_display INTERFACE
    MODULE_PICODISPLAY_ENABLED=1
)

target_link_libraries(usermod INTERFACE usermod_pico_display)

set_source_files_properties(
    ${CMAKE_CURRENT_LIST_DIR}/pico_display.c
    PROPERTIES COMPILE_FLAGS
    "-Wno-discarded-qualifiers -Wno-implicit-int"
)
