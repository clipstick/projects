set(MOD_NAME pico_display_2)
string(TOUPPER ${MOD_NAME} MOD_NAME_UPPER)
add_library(usermod_${MOD_NAME} INTERFACE)

target_sources(usermod_${MOD_NAME} INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/${MOD_NAME}.c
    ${CMAKE_CURRENT_LIST_DIR}/${MOD_NAME}.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../../libraries/${MOD_NAME}/${MOD_NAME}.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../../drivers/st7789/st7789.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../../libraries/pico_graphics/pico_graphics.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../../libraries/pico_graphics/types.cpp
)

target_include_directories(usermod_${MOD_NAME} INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_definitions(usermod_${MOD_NAME} INTERFACE
    MODULE_${MOD_NAME_UPPER}_ENABLED=1
)

target_link_libraries(usermod INTERFACE usermod_${MOD_NAME})

set_source_files_properties(
    ${CMAKE_CURRENT_LIST_DIR}/${MOD_NAME}.c
    PROPERTIES COMPILE_FLAGS
    "-Wno-discarded-qualifiers -Wno-implicit-int"
)
