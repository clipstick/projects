function (copy_module TARGET SRC DST)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/../modules/${DST}.py

        COMMAND
            cp ${SRC} ${CMAKE_CURRENT_BINARY_DIR}/../modules/${DST}.py

        DEPENDS ${src}
    )

    target_sources(${TARGET} INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/../modules/${DST}.py)
endfunction()

# Create a dummy usermod to hang our .py copies from
add_library(usermod_modules_py INTERFACE)
target_link_libraries(usermod INTERFACE usermod_modules_py)

# .py files to copy from modules_py to ports/rp2/modules
copy_module(usermod_modules_py ${CMAKE_CURRENT_LIST_DIR}/picosystem.py picosystem)
copy_module(usermod_modules_py ${CMAKE_CURRENT_LIST_DIR}/pimoroni.py pimoroni)
