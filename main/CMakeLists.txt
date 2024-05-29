cmake_minimum_required(VERSION 3.13)

add_executable(Main
    main.c
    ../zumbador/zumbador.h
    ../uart/uart.h
    ../tipo_de_lavado/tipo_lavado.h
    ../Temporizador/tempotizadorBoton.h
    ../NivelAgua/NivelAgua.h
    ../encendido-apagado/encendidoApagado.h
    ../ciclo-de-lavado/cicloLavado.h
)

pico_enable_stdio_usb(Main 1)
pico_enable_stdio_uart(Main 0)

pico_add_extra_outputs(Main)

target_link_libraries(Main pico_stdlib)