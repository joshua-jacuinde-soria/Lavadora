#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "control.h"

#define Zumbador 2

int sonidos[1] = {
    0b011001
};

int main(){
    stdio_init_all();
    gpio_init(Zumbador);
    gpio_set_dir(Zumbador, GPIO_OUT);
    

}
