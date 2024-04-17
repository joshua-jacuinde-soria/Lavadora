#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdbool.h>

#define FIRST_GPIO_DISPLAY1 12 // Primer GPIO para el primer display
#define FIRST_GPIO_DISPLAY2 20 // Primer GPIO para el segundo display
#define BUTTON_GPIO 19

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
    0x1,0x2
};

int reconocer(int numero){
    return bits[numero];;
};

void mostrar( int decenas, int unidades) {
    int cont = 0;
    while (cont < 600) {
        int display_decenas = reconocer(decenas);
        int display_unidades = reconocer(unidades);
        int displays[2] = {display_decenas, display_unidades};

        for (int i = 0; i < 2; i++) {
            int32_t mask_1 = displays[i] << FIRST_GPIO_DISPLAY1; // Invertir los bits para ánodo común en el primer display
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

int pausa(int estado){
    estado ++;
    if (estado > 2)
        estado = 1;
    return estado;
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
    int decena = 6;
    int unidad = 0;
    int pause = 1;


     while (1) {
        if (!gpio_get(BUTTON_GPIO)) {
            pause = pausa(pause);
        }
        // Espera a que se presione el botón para iniciar el temporizador
        if (pause == 2) {
            // Conteo regresivo de 60 segundos
            for (int decena = 5; decena >= 0; decena--) {
            
                for (int unidad = 9; unidad >= 0; unidad--) {
                    while 
                    mostrar(decena, unidad);
                }
            }
            break; // Sal del bucle cuando el temporizador llegue a cero
        }
    }
    return 0;
}

void temporizador(int decena, int unidad) {
    
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
