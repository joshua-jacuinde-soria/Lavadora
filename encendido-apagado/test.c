#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "encendidoApagado.h"

#define LED 28
#define BUTTON_ON_OFF 27

int main () {

    stdio_init_all();

    inicio_encendidoApagado();

    // Ciclo infinito
    while (1) {
        encendidoApagado();
        sleep_ms(150);
    }
    return 0;
}