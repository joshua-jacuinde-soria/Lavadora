#include "hardware/gpio.h"

#define LED 28
#define BOTON_I 27

int encendido_Apagado () {
    gpio_init(BOTON_I);
    gpio_set_dir(BOTON_I, GPIO_IN);
    gpio_pull_up(BOTON_I);

    bool estado = false;
    if (gpio_get(BOTON_I))
    {
        estado = !estado;
        zumbador(1);
    }
    // Encender o apagar el led de acuerdo al estado
    gpio_put(LED, estado);
    // Retornar el estado actualizado
    return estado;
}