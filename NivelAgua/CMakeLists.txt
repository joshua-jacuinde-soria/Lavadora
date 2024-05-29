cmake_minimum_required(VERSION 3.13)

add_executable(nivel
    NivelAgua.h
)

pico_enable_stdio_usb(nivel 1)
pico_enable_stdio_uart(nivel 0)

pico_add_extra_outputs(nivel)

target_link_libraries(nivel pico_stdlib)