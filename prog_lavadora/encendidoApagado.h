#include "hardware/gpio.h"
#include "pico/stdlib.h"

#define LED 28
#define BOTON_I 22
bool estado = false;

void inicio_encendidoApagado(){
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    gpio_init(BOTON_I);
    gpio_set_dir(BOTON_I, GPIO_IN);
    gpio_pull_up(BOTON_I);
}

int encendido_Apagado () {
    if (!gpio_get(BOTON_I))
    {
        estado = !estado;
        // Encender o apagar el led de acuerdo al estado
        gpio_put(LED, estado);
        zumbador(1);
    }
    
    // Retornar el estado actualizado
    return estado;
}