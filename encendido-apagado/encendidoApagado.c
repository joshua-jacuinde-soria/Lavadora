#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Definir el botton de encendido y led
#define BUTTON_ON_OFF 27
#define LED 28

int encendidoApagado (int estado) {
    // Actualizar el estado [0, 1]
    estado = !estado;
    // Encender o apagar el led de acuerdo al estado
    gpio_put(LED, estado);
    // Retornar el estado actualizado
    return estado;
}