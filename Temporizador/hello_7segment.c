#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO_DISPLAY1 12 // Primer GPIO para el primer display
#define FIRST_GPIO_DISPLAY2 19 // Primer GPIO para el segundo display
#define BUTTON_GPIO 21

// Patrones de bits para representar los números 0-9 en un display de 7 segmentos
int bits[10] = {
    0xC0, // 0
    0xF9, // 1
    0xA4, // 2
    0xB0, // 3
    0x99, // 4
    0x92, // 5
    0x82, // 6
    0xF8, // 7
    0x80, // 8
    0x98  // 9
};

int common[2] = {
    0b01,0b10
};

int reconocer(int numero){
    int valor;
    switch(numero){
        case 0:
            valor = bits[0];
            break;
        case 1:
            valor = bits[1];
            break;
        case 2:
            valor = bits[2];
            break;
        case 3:
            valor = bits[3];
            break;
        case 4:
            valor = bits[4];
            break;
        case 5:
            valor = bits[5];
            break;
        case 6:
            valor = bits[6];
            break;
        case 7:
            valor = bits[7];
            break;
        case 8:
            valor = bits[8];
            break;
        case 9:
            valor = bits[9];
    }
    return valor;
};

void mostrar( int decenas, int unidades) {
    int cont = 0;
    while (cont < 100) {
        int cosa1 = reconocer(decenas);
        int cosa2 = reconocer(unidades);
        int cosas[2] = {cosa1, cosa2};
        for (int i = 0; i < 2; i++) {
            int32_t mask_1 = cosas[i] << FIRST_GPIO_DISPLAY1; // Invertir los bits para ánodo común en el primer display
            gpio_set_mask(mask_1); // Manda el mask
            int32_t mask_2 = common[i] << FIRST_GPIO_DISPLAY2; // Invertir los bits para ánodo común en el segundo display
            // Encender ambos displays
            gpio_set_mask(mask_2);
            sleep_ms(2);
            // Apagar ambos displays
            gpio_clr_mask(mask_2);
            gpio_clr_mask(mask_1);
        }
        cont++;
    }
}


int main()
{
    stdio_init_all();
    printf("Temporizador de 60 segundos - Presiona el botón para iniciar\n");

    // Inicialización de los GPIOs para los displays y el botón
    for (int gpio = FIRST_GPIO_DISPLAY1; gpio < FIRST_GPIO_DISPLAY1 + 7; gpio++)
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    for (int gpio = FIRST_GPIO_DISPLAY2; gpio < FIRST_GPIO_DISPLAY2 + 2; gpio++)
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    // Variables para el temporizador
    int seconds = 60;

    // Bucle principal
    while (1)
    {
        // Espera a que se presione el botón para iniciar el temporizador
        if (gpio_get(BUTTON_GPIO))
        {
            // Conteo regresivo de 60 segundos
            for (int i = 0; i < 60; i++)
            {
                mostrar((seconds / 10), (seconds % 10)); // Muestra el display de 60 segundos
                // displayNumber(seconds / 10, FIRST_GPIO_DISPLAY1); // Muestra el dígito de las decenas
                // mostrar();
                // displayNumber(seconds % 10, FIRST_GPIO_DISPLAY1); // Muestra el dígito de las unidades
                // mostrar();
                sleep_ms(1000);
                seconds--;
            }

            break;           // Sal del bucle cuando el temporizador llegue a cero
        }
    }

    // Detén el temporizador
    // displayNumber(0, FIRST_GPIO_DISPLAY1);
    // displayNumber(0, FIRST_GPIO_DISPLAY2);

    return 0;
}

// gpio_init(BUTTON_GPIO);
//     gpio_set_dir(BUTTON_GPIO, GPIO_IN);
//     // We are using the button to pull down to 0v when pressed, so ensure that when
//     // unpressed, it uses internal pull ups. Otherwise when unpressed, the input will
//     // be floating.
//     gpio_pull_up(BUTTON_GPIO);

//     int estado = 0;
//     int pausa = 0;

// while (1) {
//     //if (//funcion temporizador finalizado)
//         // break
//     if (!gpio_get(BUTTON_GPIO) && estado == 0){
//         // funcion iniciar temportizador
//         estado = 1;
//     } else if (!gpio_get(BUTTON_GPIO) && pausa == 0) {
//         // funcion pause temporizador
//         pausa = 1
//     }}