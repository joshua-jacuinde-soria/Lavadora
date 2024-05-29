#include    <stdio.h>
#include    "pico/stdlib.h"
#include    "hardware/gpio.h"
#include    "cicloLavado.h"

#define BUTTON_CICLO 7
#define LED_SUAVE 4
#define LED_PESADO 5
#define LED_RAPIDO 6

volatile int flag = 0;

void irq_handler() {
    cicloLavado();
    flag = 1; // Flag to indicate that the button was pressed
}

int main() {
    stdio_init_all();

    inicio_cicloLavado();

    // Test with interruptions handling
    // gpio_set_irq_enabled_with_callback(BUTTON_CICLO, GPIO_IRQ_EDGE_RISE, true, &irq_handler);

    while(1) {
        if (flag) {
            printf("Button pressed\n");
            flag = 0;
            int ciclo = getCycleStatus();
            printf("Cycle status: %d\n", ciclo);
        }
        sleep_ms(150);
    }
    return 0;
}

