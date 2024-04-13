#include    <stdio.h>
#include    "pico/stdlib.h"
#include    "hardware/gpio.h"

int main() {
    const uint SUAVE = 4;
    const uint PESADO = 5;
    const uint RAPIDO = 6;

    gpio_init(SUAVE);
    gpio_init(PESADO);
    gpio_init(RAPIDO);

    gpio_set_dir(SUAVE, GPIO_OUT);
    gpio_set_dir(PESADO, GPIO_OUT);
    gpio_set_dir(RAPIDO, GPIO_OUT);

}