#include    <stdio.h>
#include    "pico/stdlib.h"
#include    "hardware/gpio.h"
#include    "cicloLavado.h"

#define BUTTON_CICLO 7
#define LED_SUAVE 4
#define LED_PESADO 5
#define LED_RAPIDO 6

int main() {
    stdio_init_all();

    inicio_cicloLavado();

    while(1) {
        cicloLavado();
        sleep_ms(150);
    }
    return 0;
}