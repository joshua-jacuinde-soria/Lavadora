#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdbool.h>

#define FIRST_GPIO_DISPLAY1 12 // Primer GPIO para el primer display
#define FIRST_GPIO_DISPLAY2 20 // Primer GPIO para el segundo display
#define BUTTON_GPIO 19

int decena;
int unidad = 0;
int estado_2;

bool ultimo_estado_boton = false;
bool boton_presionado = false;

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
    0x2,0x1
};


void mostrar(int decenas, int unidades) {
    int display_decenas = bits[decenas];
    int display_unidades = bits[unidades];
    int cont = 0;
    int displays[2] = {display_decenas, display_unidades};
    while (cont < 200){
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
    cont ++;
    }
}



void inicio_visualizador(){
    // Inicialización de los GPIOs para los displays y el botón
    for (int gpio = FIRST_GPIO_DISPLAY1; gpio < FIRST_GPIO_DISPLAY1 + 7; gpio++)
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }

    for (int gpio = FIRST_GPIO_DISPLAY2; gpio < FIRST_GPIO_DISPLAY2 + 2; gpio++)
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);
    estado_2 = 0;
}

int pausa_vis(){
    if (!gpio_get(BUTTON_GPIO))
    {
        estado_2 ++;
    }
    if (estado_2 > 2)
        estado_2 = 1;
    
    return estado_2;
}

void visualizador(int valor, int pausa)
{

    if (valor == 0){
        decena = 3;
    }
    else if (valor == 1)   
    {
        decena = 2;
    }
    else
    {
        decena = 1;
    }

    if (pausa == 1){
        while (decena >= 0 )
        {
            pausa = pausa_vis();
            while (pausa == 2 )
            {
                mostrar(decena,unidad);
                sleep_ms(500);
            }
            mostrar(decena, unidad);
            unidad--;
            if (unidad < 0) {
                unidad = 9;
                decena--;
        }
        
        
    }

    }

    
    // while (1) {
    // bool estado_boton = !gpio_get(BUTTON_GPIO); // Leer el estado del botón 

    // // Detectar si el botón ha sido presionado (cambio de estado de alto a bajo)
    // if (!ultimo_estado_boton && estado_boton) {
    //     boton_presionado = true;
    // }
    // ultimo_estado_boton = estado_boton;

    // // Verificar si se ha presionado el botón
    // if (boton_presionado) {
    //     boton_presionado = false; // Reiniciar el indicador de presionado

    //     // Alternar entre pausa y ejecución del temporizador
    //     pause = pausa(pause);

    //     // Si el temporizador está en pausa, mostrar el valor actual y quedarse pausado
    //     if (pause == 1) {
    //         // Continuar mostrando el valor actual mientras el temporizador está pausado
    //         while (pause == 1) {
    //             mostrar(decena, unidad); 
    //             // Esperar un breve período de tiempo antes de volver a verificar el estado del botón
    //             sleep_ms(50);
    //             // Verificar si se presiona el botón para reanudar el temporizador
    //             estado_boton = !gpio_get(BUTTON_GPIO);
    //             if (estado_boton) {
    //                 pause = pausa(pause); // Alternar entre pausa y ejecución del temporizador
    //                 break; // Salir del bucle while interno
    //             }
    //         }
    //         continue; // Vuelve al inicio del bucle while externo
    //     }
    // }

    // // Si el temporizador no está en pausa, continuar con el conteo
    // if (pause == 2) {
    //     
    //     }
}
