cmake_minimum_required(VERSION 3.13)

add_executable(EncendidoApagado
    test.c 
    encendidoApagado.h
)

pico_enable_stdio_usb(EncendidoApagado 1)
pico_enable_stdio_uart(EncendidoApagado 0)

pico_add_extra_outputs(EncendidoApagado)

target_link_libraries(EncendidoApagado pico_stdlib)