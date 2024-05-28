cmake_minimum_required(VERSION 3.13)

add_executable(Main
    main.c
    cicloLavado.h
    encendidoApagado.h
    hello_7segment.h
    NivelAgua.h
    tipo_de_lavado.h
    zumbador.h
    uart.h
)

pico_enable_stdio_usb(Main 1)
pico_enable_stdio_uart(Main 0)

pico_add_extra_outputs(Main)

target_link_libraries(Main pico_stdlib)