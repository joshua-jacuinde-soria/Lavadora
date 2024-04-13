#include    <stdio.h>
#include    "pico/stdlib.h"
#include    "hardware/gpio.h"

#define BUTTON_CICLO 7

int main() {

    stdio_init_all();

    const uint LED_SUAVE = 4;
    const uint LED_PESADO = 5;
    const uint LED_RAPIDO = 6;

    gpio_init(LED_SUAVE);
    gpio_init(LED_PESADO);
    gpio_init(LED_RAPIDO);

    gpio_set_dir(LED_SUAVE, GPIO_OUT);
    gpio_set_dir(LED_PESADO, GPIO_OUT);
    gpio_set_dir(LED_RAPIDO, GPIO_OUT);

    // init button
    gpio_init(BUTTON_CICLO);
    gpio_set_dir(BUTTON_CICLO, GPIO_IN);
    gpio_pull_up(BUTTON_CICLO);

    int ciclo = 2;
    while (1) {
        if (!gpio_get(BUTTON_CICLO)) {
            ciclo++;
            if (ciclo > 2) {
                ciclo = 0;
            }
            gpio_put(LED_SUAVE, ciclo == 0);
            gpio_put(LED_PESADO, ciclo == 1);
            gpio_put(LED_RAPIDO, ciclo == 2);
            printf("Boton presionado. Ciclo de lavado: %d\n", ciclo);
        } else {
            printf("Ciclo de lavado: %d\n", ciclo);
        }
        sleep_ms(100);
    }
}