#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO_DISPLAY1 2 // Primer GPIO para el primer display
#define FIRST_GPIO_DISPLAY2 9 // Primer GPIO para el segundo display
#define BUTTON_GPIO (FIRST_GPIO_DISPLAY2 + 7) // GPIO para el botón

// Patrones de bits para representar los números 0-9 en un display de 7 segmentos
int bits[10] = {
    0x3f, // 0
    0x06, // 1
    0x5b, // 2
    0x4f, // 3
    0x66, // 4
    0x6d, // 5
    0x7d, // 6
    0x07, // 7
    0x7f, // 8
    0x67  // 9
};

void displayNumber(int number, int first_gpio) {
    // Dado un número, muestra el número en el display correspondiente
    int32_t mask = bits[number % 10] << first_gpio;
    gpio_set_mask(mask);
}

int main() {
    stdio_init_all();
    printf("Temporizador de 60 segundos - Presiona el botón para iniciar\n");

    // Inicialización de los GPIOs para los displays y el botón
    for (int gpio = FIRST_GPIO_DISPLAY1; gpio < FIRST_GPIO_DISPLAY1 + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }

    for (int gpio = FIRST_GPIO_DISPLAY2; gpio < FIRST_GPIO_DISPLAY2 + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }

    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    // Variables para el temporizador
    int seconds = 60;

    // Bucle principal
    while (1) {
        // Espera a que se presione el botón para iniciar el temporizador
        if (!gpio_get(BUTTON_GPIO)) {
            // Conteo regresivo de 60 segundos
            for (int i = 0; i < 60; i++) {
                displayNumber(seconds / 10, FIRST_GPIO_DISPLAY1); // Muestra el dígito de las decenas
                displayNumber(seconds % 10, FIRST_GPIO_DISPLAY2); // Muestra el dígito de las unidades
                sleep_ms(1000);
                seconds--;
            }
            break; // Sal del bucle cuando el temporizador llegue a cero
        }
    }

    // Detén el temporizador
    displayNumber(0, FIRST_GPIO_DISPLAY1);
    displayNumber(0, FIRST_GPIO_DISPLAY2);

    return 0;
}
