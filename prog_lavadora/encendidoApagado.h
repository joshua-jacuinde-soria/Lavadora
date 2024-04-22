#include "hardware/gpio.h"

#define LED 28
#define BOTON 27

int encendido_Apagado () {
    gpio_init(BOTON);
    gpio_set_dir(BOTON, GPIO_IN);
    gpio_pull_up(BOTON);

    bool estado = false;
    if (gpio_get(BOTON))
    {
        estado = !estado;
        zumbador(1);
    }
    // Encender o apagar el led de acuerdo al estado
    gpio_put(LED, estado);
    // Retornar el estado actualizado
    return estado;
}