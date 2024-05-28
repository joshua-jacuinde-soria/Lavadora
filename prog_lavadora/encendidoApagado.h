#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "uart.h"

#define LED_IO 28
#define BOTON_I 22
bool estado = false;

void inicio_encendidoApagado(){
    gpio_init(LED_IO);
    gpio_set_dir(LED_IO, GPIO_OUT);
    gpio_init(BOTON_I);
    gpio_set_dir(BOTON_I, GPIO_IN);
    gpio_pull_up(BOTON_I);
}

int encendido_Apagado () {
    if (!gpio_get(BOTON_I))
    {
        estado = !estado;
        // Encender o apagar el led_IO de acuerdo al estado
        gpio_put(LED_IO, estado);
        zumbador(1);
    }
    send_cmd(estado, 0x61);
    // Retornar el estado actualizado
    return estado;
}