#include    <stdio.h>
#include    "pico/stdlib.h"
#include    "hardware/gpio.h"

// Button
#define BUTTON_CICLO 7

int main() {
    // Inicializar la librería stdio
    stdio_init_all();

    // Definir  los pines de los LEDs
    const uint LED_SUAVE = 4;
    const uint LED_PESADO = 5;
    const uint LED_RAPIDO = 6;

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
        // Leer el estado del botón
        if (!gpio_get(BUTTON_CICLO)) {
            // Cambiar el ciclo de lavado
            ciclo++;
            if (ciclo > 2) {
                ciclo = 0;
            }
            // Encender el LED correspondiente al ciclo de lavado
            gpio_put(LED_SUAVE, ciclo == 0);
            gpio_put(LED_PESADO, ciclo == 1);
            gpio_put(LED_RAPIDO, ciclo == 2);
            printf("Boton presionado. Ciclo de lavado: %d\n", ciclo);
        }
        sleep_ms(100);  // Se tiene que testear el tiempo de espera para que no 
                        //haga saltos de ciclos inesperados
    }
}