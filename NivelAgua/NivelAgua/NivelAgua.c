/*
    Universidad Autónoma Metropilitana Unidad Cuajimalpa
    Alumno: Sonia Maurilia Gonzalez Villa
    Matricula: 2193077059
    Profesor: Dr. Adán Geovanni Medrano Chávez.
    UEA: Microconroladores.

*/

//Se importan las librerias a utilizar
#include <stdio.h>
#include "pico/stdlib.h"
#include "NivelAgua_gen.h"

/* Aquí se definen constantes para los números de pin de 
los GPIOs a los que están conectados los LEDs y el botón. */ 
// La funcion de nivel de agua requerira 4 puertos del microcontrolador

#define LED_Bajo 0           // Led para nivel de agua bajo
#define LED_Medio 1        // Led para nivel de agua medio
#define LED_Alto 2    // Led para nivel de agua alto
#define BOTON 3              // Botón de acción

int main() {
    
    stdio_init_all();
    
    /* Cada llamada a gpio_init() inicializa un pin GPIO. 
    Esta función debe ser llamada en cada pin antes de 
    configurarlo para entrada o salida.*/

    gpio_init(LED_Bajo);
    gpio_init(LED_Medio);
    gpio_init(LED_Alto);
    gpio_init(BOTON);

    /* Estas llamadas a gpio_set_dir() configuran la dirección
    de cada pin. Los pines conectados a los LEDs se configuran 
    como salidas (GPIO_OUT), y el pin conectado al botón se 
    configura como entrada (GPIO_IN) .*/

    gpio_set_dir(LED_Bajo, GPIO_OUT);
    gpio_set_dir(LED_Medio, GPIO_OUT);
    gpio_set_dir(LED_Alto, GPIO_OUT);
    gpio_set_dir(BOTON, GPIO_IN);

    /* La función 'gpio_pull_up(pin)' es utilizada para activar
    la resistencia de pull-up interna para un pin GPIO específico*/

    gpio_pull_up(BOTON);


    int led_state = 2;
    //int signal = 2;
    
    while (1) {
        if (!gpio_get(BOTON) == 1) {
            led_state++;
            
            if (led_state > 2)
            {
                led_state = 0;
            }

            gpio_put(LED_Bajo, led_state == 0);
            gpio_put(LED_Medio, led_state == 1);
            gpio_put(LED_Alto, led_state == 2);

        }

        /* 'sleep_ms(100)' proporciona un retardo para evitar rebotes del botón*/
        sleep_ms(100);
    }

    return 0;
    
}