add_executable(uart
    uart.c
    uart.h
)

target_link_libraries(uart pico_stdlib)
pico_add_extra_outputs(uart)