add_executable(temporizadorBoton.h
        hello_7segment.c
        )

# pull in common dependencies
target_link_libraries(temporizadorBoton.h pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(hello_7segment)

# add url via pico_set_program_url
# example_auto_set_url(hello_7segment)
