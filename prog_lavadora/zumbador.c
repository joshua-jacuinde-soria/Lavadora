#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define Zumbador 2

int sonidos[8] = {
    1,0,1,1,0,1,0,1
};

int main(){
    stdio_init_all();
    gpio_init(Zumbador);
    gpio_set_dir(Zumbador, GPIO_OUT);
    
    while (true)
    {
        for (int i = 0; i < 8; i++)
        {
            int32_t mask = sonidos[i] << Zumbador;
            gpio_set_mask(mask);
            sleep_ms(20);
            gpio_clr_mask(mask);
        }
    }
         

}
