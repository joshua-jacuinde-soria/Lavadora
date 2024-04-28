add_executable(temporizadorBoton.h
        )

# pull in common dependencies
target_link_libraries(temporizadorBoton.h pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(temporizadorBoton.h)

# add url via pico_set_program_url
# example_auto_set_url(hello_7segment)
