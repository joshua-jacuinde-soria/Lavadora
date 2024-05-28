cmake_minimum_required(VERSION 3.13)

add_executable(tipo
    pruebas_tipo_lavado.c
    tipo_lavado.h
)

pico_enable_stdio_usb(tipo 1)
pico_enable_stdio_uart(tipo 0)

pico_add_extra_outputs(tipo)

target_link_libraries(tipo pico_stdlib)
