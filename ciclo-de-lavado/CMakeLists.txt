add_executable(ciclo-de-lavado
        ciclo-lavado.c
        )

# pull in common dependencies
target_link_libraries(ciclo-de-lavado pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(ciclo-de-lavado)

# add url via pico_set_program_url
# example_auto_set_url(hello_7segment)
