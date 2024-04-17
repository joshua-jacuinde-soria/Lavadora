#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED 28

int encendidoApagado (int estado) {
    // Actualizar el estado [0, 1]
    estado = !estado;
    // Encender o apagar el led de acuerdo al estado
    gpio_put(LED, estado);
    // Retornar el estado actualizado
    return estado;
}