#ifndef ENCENDIDOAPAGADO_H
#define ENCENDIDOAPAGADO_H

#include "hardware/gpio.h"

#define LED 28
#define BUTTON 22
bool estado = 0;

void inicio_encendidoApagado() {
    // Inicializar el pin del LED
    gpio_init(LED);
    // Configurar el pin del LED como salida
    gpio_set_dir(LED, GPIO_OUT);
    // Inicializar el boton
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
    // Apagar el LED
    gpio_put(LED, 0);
}

bool encendidoApagado () {
    // Actualizar el estado [0, 1]
    estado = !estado;
    // Encender o apagar el led de acuerdo al estado
    gpio_put(LED, estado);
    // Retornar el estado actualizado
    return estado;
}

#endif