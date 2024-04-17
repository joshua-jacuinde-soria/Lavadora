#include    <stdio.h>
#include    "pico/stdlib.h"
#include    "hardware/gpio.h"
#include    "cicloLavado.h"

#define BUTTON_CICLO 7
#define LED_SUAVE 4
#define LED_PESADO 5
#define LED_RAPIDO 6

int main() {
    stdio_init_all();

    // Inicializar los pines de los LEDs
    gpio_init(LED_SUAVE);
    gpio_init(LED_PESADO);
    gpio_init(LED_RAPIDO);

    // Configurar los pines de los LEDs como salida
    gpio_set_dir(LED_SUAVE, GPIO_OUT);
    gpio_set_dir(LED_PESADO, GPIO_OUT);
    gpio_set_dir(LED_RAPIDO, GPIO_OUT);

    // Inicializar el pin del botón
    gpio_init(BUTTON_CICLO);
    gpio_set_dir(BUTTON_CICLO, GPIO_IN);
    gpio_pull_up(BUTTON_CICLO);

    int ciclo = 2;
    while (1) {
        if (!gpio_get(BUTTON_CICLO)) {
            ciclo = cicloLavado(ciclo);
        }
        sleep_ms(200);
    }
}