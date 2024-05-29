#ifndef CICLO_LAVADO_H
#define CICLO_LAVADO_H

#include "hardware/gpio.h"
#include "../zumbador/zumbador.h"
#include "../uart/uart.h"

// Definir  los pines de los LEDs
#define LED_SUAVE 4
#define LED_PESADO 5
#define LED_RAPIDO 6
#define BOTON_CICLO 7

int cycleStatus;

int cicloLavado() {
    if(!gpio_get(BOTON_CICLO)) {
        cycleStatus++;
        if (cycleStatus > 2) {
            cycleStatus = 0;
        }
        // Enviar el comando al receptor
        send_cmd(cycleStatus, 0x65);
        // ZUMBADOR
        zumbador(1);
    }

    // Encender el LED correspondiente al ciclo de lavado
    gpio_put(LED_SUAVE, cycleStatus == 0);
    gpio_put(LED_PESADO, cycleStatus == 1);
    gpio_put(LED_RAPIDO, cycleStatus == 2);

    return cycleStatus;
}

void inicio_cicloLavado() {
    // Inicializar los pines de los LEDs
    gpio_init(LED_SUAVE);
    gpio_init(LED_PESADO);
    gpio_init(LED_RAPIDO);
    // Configurar los pines de los LEDs como salida
    gpio_set_dir(LED_SUAVE, GPIO_OUT);
    gpio_set_dir(LED_PESADO, GPIO_OUT);
    gpio_set_dir(LED_RAPIDO, GPIO_OUT);
    // Inicializar el boton_CICLO
    gpio_init(BOTON_CICLO);
    gpio_set_dir(BOTON_CICLO, GPIO_IN);
    gpio_pull_up(BOTON_CICLO);

    // Apagar los LEDs
    gpio_put(LED_SUAVE, 0);
    gpio_put(LED_PESADO, 0);
    gpio_put(LED_RAPIDO, 0);

    cycleStatus = -1;
}

#endif