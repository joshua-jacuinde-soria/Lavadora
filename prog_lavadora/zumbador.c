
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define Zumbador 2

int sonidos[8] = {
    1, 0, 0, 0, 1, 1, 0, 1
};

int tiempos[8] = {
  30,30,10,30,30,20,10,10
};

int main(){
    //stdio_init_all();
    gpio_init(Zumbador);
    gpio_set_dir(Zumbador, GPIO_OUT);
    
    while (true)
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
