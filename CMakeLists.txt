cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(Lavadora_project C CXX ASM)
set(CMAKE_C_STANDAR 11)
set(CMAKE_CXX_STANDARD 17)
# set(PICO_BOARD pico_w)

pico_sdk_init()

add_subdirectory(ciclo-de-lavado)
add_subdirectory(encendido-apagado)
add_subdirectory(main)
add_subdirectory(NivelAgua)
add_subdirectory(Temporizador)
add_subdirectory(tipo_de_lavado)
# add_subdirectory(zumbador)
add_subdirectory(uart)