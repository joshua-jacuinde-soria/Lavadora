# cmake_minimum_required(VERSION 3.13)

add_executable(tipo_de_lavado
	#tipo_de_lavado.c
        tipo_de_lavado.h
        pruebas_tipo_lavado.c
        tipo_lavado.h
        )

# pull in common dependencies
target_link_libraries(tipo_de_lavado pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(tipo_de_lavado)

# add url via pico_set_program_url
# example_auto_set_url(hello_7segment)
