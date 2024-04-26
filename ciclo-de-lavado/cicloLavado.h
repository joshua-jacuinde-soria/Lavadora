#ifndef CICLO_LAVADO_H
#define CICLO_LAVADO_H

#include "hardware/gpio.h"
#include "../zumbador/zumbador.h"

// Definir  los pines de los LEDs
#define LED_SUAVE 4
#define LED_PESADO 5
#define LED_RAPIDO 6
#define BOTON 7

int cycleStatus;

void inicio_cicloLavado() {
    // Inicializar los pines de los LEDs
    gpio_init(LED_SUAVE);
    gpio_init(LED_PESADO);
    gpio_init(LED_RAPIDO);
    // Configurar los pines de los LEDs como salida
    gpio_set_dir(LED_SUAVE, GPIO_OUT);
    gpio_set_dir(LED_PESADO, GPIO_OUT);
    gpio_set_dir(LED_RAPIDO, GPIO_OUT);
    // Inicializar el boton
    gpio_init(BOTON);
    gpio_set_dir(BOTON, GPIO_IN);
    gpio_pull_up(BOTON);

    // Apagar los LEDs
    gpio_put(LED_SUAVE, 0);
    gpio_put(LED_PESADO, 0);
    gpio_put(LED_RAPIDO, 0);

    cycleStatus = -1;
}

int cicloLavado() {
    // Cuando el boton sea presionado
    if (!gpio_get(BOTON)) {
        cycleStatus++;
        zumbador(1);
    }
    // Si el ciclo de lavado es mayor a 2, reiniciar el ciclo
    if (cycleStatus > 2) {
        cycleStatus = 0;
    }
    // Encender el LED correspondiente al ciclo de lavado
    gpio_put(LED_SUAVE, cycleStatus == 0);
    gpio_put(LED_PESADO, cycleStatus == 1);
    gpio_put(LED_RAPIDO, cycleStatus == 2);
}

#endif