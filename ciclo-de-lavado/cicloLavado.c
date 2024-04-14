#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

unsigned cicloLavado(unsigned cycleStatus) {
    // Cambiar el ciclo de lavado
    cycleStatus++;
    if (cycleStatus > 2) {
        cycleStatus = 0;
    }
    // Definir  los pines de los LEDs
    const uint LED_SUAVE = 4;
    const uint LED_PESADO = 5;
    const uint LED_RAPIDO = 6;
    // Encender el LED correspondiente al ciclo de lavado
    gpio_put(LED_SUAVE, cycleStatus == 0);
    gpio_put(LED_PESADO, cycleStatus == 1);
    gpio_put(LED_RAPIDO, cycleStatus == 2);

    return cycleStatus;
}