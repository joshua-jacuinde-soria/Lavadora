 #ifndef ZUMBADOR_H
 #define ZUMBADOR_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define Zumbador 26

int sonidos[2][8] = {
    {1, 1, 0, 1, 0, 1, 0, 0},{1, 0, 0, 0, 0, 0, 1, 1}
    };

int tiempos[8] = {
  10, 30, 10, 30, 10, 30, 10, 10
};


void zumbador(int seleccion){
    gpio_init(Zumbador);
    gpio_set_dir(Zumbador, GPIO_OUT);
    for (int i = 0; i < 8; i++)
        {
            int32_t mask = sonidos[seleccion][i] << Zumbador;
            gpio_set_mask(mask);
            sleep_ms(tiempos[i]);
            gpio_clr_mask(mask);
        }   
    return;     
}

// int main(){
//     gpio_init(boton);
//     gpio_set_dir(boton, GPIO_IN);
//     gpio_pull_up(boton);

//     gpio_init(boton_2);
//     gpio_set_dir(boton_2, GPIO_IN);
//     gpio_pull_up(boton_2);
    
//     stdio_init_all();

//     int seleccion;
//     while (true)
//     {
        
//         if (!gpio_get(boton))
//         {
//             seleccion = 0;
//             zumbador(seleccion);
//         }
//         else if (!gpio_get(boton_2))
//         {
//             seleccion = 1;
//             zumbador(seleccion);
//         }
//         }    
// }

#endif