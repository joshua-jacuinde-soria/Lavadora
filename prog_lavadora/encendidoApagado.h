#include "hardware/gpio.h"

#define LED 28
#define BOTON_I 27

void inicio_encendidoApagado(){
    stdio_init_all();
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    gpio_init(BOTON_I);
    gpio_set_dir(BOTON_I, GPIO_IN);
    gpio_pull_up(BOTON_I);
}

int encendido_Apagado () {
    bool estado = false;
    if (!gpio_get(BOTON_I))
    {
        estado = !estado;
        zumbador(1);
    }
    // Encender o apagar el led de acuerdo al estado
    if (estado){
        gpio_put(LED, 1);
    }
    else
    {
        gpio_put(LED,0);
    }
    
    // Retornar el estado actualizado
    return estado;
}