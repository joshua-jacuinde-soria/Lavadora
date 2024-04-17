#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED 28
#define BUTTON_ON_OFF 27

int main () {
    // Inicializar la librería stdio
    stdio_init_all();
    // Inicializar LED
    gpio_init(LED);
    // Configurar el pin del led como salida
    gpio_set_dir(LED, GPIO_OUT);
    // Inicializar el pin del botón como entrada
    gpio_init(BUTTON_ON_OFF);
    // Configurar el pin del botón como entrada
    gpio_set_dir(BUTTON_ON_OFF, GPIO_IN);
    // Configurar el pull-up del botón
    gpio_pull_up(BUTTON_ON_OFF);
    // Declarar una variable para almacenar el estado del led
    int estado = 0;
    // Ciclo infinito
    while (1) {
        if (!gpio_get(BUTTON_ON_OFF)) {
            // Actualizar el estado [0, 1]
            estado = encedidoApagado(estado);
            // Esperar 500 ms
            sleep_ms(500);
            printf("Estado: %d\n", estado);
        }
    }
    return 0;
}