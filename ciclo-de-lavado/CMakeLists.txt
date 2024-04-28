cmake_minimum_required(VERSION 3.13)

add_executable(CicloLavado
    test.c
    cicloLavado.h
)

pico_enable_stdio_usb(CicloLavado 1)
pico_enable_stdio_uart(CicloLavado 0)

pico_add_extra_outputs(CicloLavado)

target_link_libraries(CicloLavado pico_stdlib)