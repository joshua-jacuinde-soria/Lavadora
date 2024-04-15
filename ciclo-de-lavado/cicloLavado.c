#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Definir  los pines de los LEDs
#define LED_SUAVE 4
#define LED_PESADO 5
#define LED_RAPIDO 6
int cicloLavado(int cycleStatus) {
    // Cambiar el ciclo de lavado
    cycleStatus++;
    if (cycleStatus > 2) {
        cycleStatus = 0;
    }
    // Encender el LED correspondiente al ciclo de lavado
    gpio_put(LED_SUAVE, cycleStatus == 0);
    gpio_put(LED_PESADO, cycleStatus == 1);
    gpio_put(LED_RAPIDO, cycleStatus == 2);

    return cycleStatus;
}