 #ifndef ZUMBADOR_H
 #define ZUMBADOR_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define Zumbador 26

int sonidos[2][8] = {
    {1, 0, 1, 1, 0, 1, 1, 0},{1, 0, 0, 0, 0, 0, 1, 1}
    };

int tiempos[8] = {
  10, 30, 10, 30, 10, 30, 10, 10
};

void inicio_zumbador(){
    gpio_init(Zumbador);
    gpio_set_dir(Zumbador, GPIO_OUT);
}

void zumbador(int seleccion){
    for (int i = 0; i < 8; i++)
        {
            int32_t mask = sonidos[seleccion][i] << Zumbador;
            gpio_set_mask(mask);
            sleep_ms(tiempos[i]);
            gpio_clr_mask(mask);
        }   
    return;     
}
#endif