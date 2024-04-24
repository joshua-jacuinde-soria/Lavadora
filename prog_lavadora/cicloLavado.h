#include "hardware/gpio.h"
#include "zumbador.h"

// Definir  los pines de los LEDs
#define LED_SUAVE 4
#define LED_PESADO 5
#define LED_RAPIDO 6
#define BOTON 7

void inicio_ciclolavado(){
    gpio_init(BOTON);
    gpio_set_dir(BOTON, GPIO_IN);
    gpio_init(LED_SUAVE);
    gpio_set_dir(LED_SUAVE, GPIO_OUT);
    gpio_init(LED_PESADO);
    gpio_set_dir(LED_PESADO, GPIO_OUT);
    gpio_init(LED_RAPIDO);
    gpio_set_dir(LED_RAPIDO, GPIO_OUT);
    gpio_pull_up(BOTON);

}

int cicloLavado() {

    int cycleStatus = 0;
    // Cambiar el ciclo de lavado
    if (!gpio_get(BOTON))
    {
        cycleStatus++;  
        zumbador(1);
    }
    
    if (cycleStatus > 2) {
        cycleStatus = 0;
    }
    // Encender el LED correspondiente al ciclo de lavado
    gpio_put(LED_SUAVE, cycleStatus == 0);
    gpio_put(LED_PESADO, cycleStatus == 1);
    gpio_put(LED_RAPIDO, cycleStatus == 2);

    return cycleStatus;
}