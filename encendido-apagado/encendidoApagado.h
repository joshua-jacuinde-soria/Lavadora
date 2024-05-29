#ifndef ENCENDIDOAPAGADO_H
#define ENCENDIDOAPAGADO_H

#include "hardware/gpio.h"
#include "../uart/uart.h"
#include <stdbool.h>

#define LED_IO 28
#define BUTTON_IO 22
bool estado = false;

void inicio_encendidoApagado() {
    // Inicializar el pin del LED_IO
    gpio_init(LED_IO);
    // Configurar el pin del LED_IO como salida
    gpio_set_dir(LED_IO, GPIO_OUT);
    // Inicializar el boton
    gpio_init(BUTTON_IO);
    gpio_set_dir(BUTTON_IO, GPIO_IN);
    gpio_pull_up(BUTTON_IO);
    // Apagar el LED_IO
    gpio_put(LED_IO, 0);
}

bool encendidoApagado () {
    // // Actualizar el estado [0, 1]
    // estado = !estado;
    // // Enviar el comando al receptor
    // send_cmd(estado, 0x61);
    // // Encender o apagar el led de acuerdo al estado
    // gpio_put(LED_IO, estado);
    // // Retornar el estado actualizado
    // return estado;
    if(!gpio_get(BUTTON_IO)){
        estado = !estado;
        send_cmd(estado, 0x61);
        gpio_put(LED_IO, estado);
    }
    return estado;
}

#endif