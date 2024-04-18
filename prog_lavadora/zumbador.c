
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define Zumbador 16
#define boton 0

int sonidos[8] = {
    1, 1, 0, 1, 0, 1, 0, 0
};

int tiempos[8] = {
  10, 30, 10, 30, 10, 30, 10, 10
};


int main(){
    stdio_init_all();
    gpio_init(Zumbador);
    gpio_set_dir(Zumbador, GPIO_OUT);

    gpio_init(boton);
    gpio_set_dir(boton, GPIO_IN);
    gpio_pull_up(boton);
    
    while (true)
    {
        if (!gpio_get(boton))
        {
            for (int i = 0; i < 8; i++)
            {
                int32_t mask = sonidos[i] << Zumbador;
                gpio_set_mask(mask);
                sleep_ms(tiempos[i]);
                gpio_clr_mask(mask);
            }
        }
        
        
    }
         

}
