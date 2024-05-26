cmake_minimum_required(VERSION 3.13)


add_executable(LAVADORA
    zumbador.h
    hello_7segment.h
    tipo_de_lavado.h
    encendidoApagado.h
    cicloLavado.h
    NivelAgua.h
    main.c
    )

pico_enable_stdio_usb(LAVADORA 1)
pico_enable_stdio_uart(LAVADORA 0)

pico_add_extra_outputs(LAVADORA)

target_link_libraries(LAVADORA pico_stdlib)