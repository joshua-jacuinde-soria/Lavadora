#include    <stdio.h>
#include    "pico/stdlib.h"
#include    "hardware/gpio.h"

#define BUTTON_CICLO 7

int main() {
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
        if (gpio_get(BUTTON_CICLO) == 0) {
            ciclo++;
            if (ciclo > 2) {
                ciclo = 0;
                gpio_put(LED_RAPIDO, 0);
                sleep_ms(250);
                gpio_put(LED_SUAVE, 1);
            } else if (ciclo == 1) {
                gpio_put(LED_SUAVE, 0);
                sleep_ms(250);
                gpio_put(LED_PESADO, 1);
            } else if (ciclo == 2) {
                gpio_put(LED_PESADO, 0);
                sleep_ms(250);
                gpio_put(LED_RAPIDO, 1);
            }
            printf("Boton presionado. Ciclo de lavado: %d\n", ciclo);
        } else {
            printf("Ciclo de lavado: %d\n", ciclo);
        }
        sleep_ms(1000);
    }
}