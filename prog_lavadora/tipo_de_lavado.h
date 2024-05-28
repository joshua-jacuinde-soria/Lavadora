/*
    Universidad Autónoma Metropilitana.
    UEA: Microconroladores.

*/

// Importamos las librerias necesarias para poder trabajar
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "zumbador.h"
#include "uart.h"

/* Aquí se definen constantes para los números de pin de 
los GPIOs a los que están conectados los LEDs y el botón. */ 

const uint LED_lavar = 8;           // Led para lavar
const uint LED_enjuagar = 9;        // Led para enjuagar
const uint LED_centrifugar = 10;    // Led para centrifugar
const uint BOTON_2 = 11;              // Botón de acción
int led_state_2 = 6;

void inicio_tipolavado(){
    
    /* Cada llamada a gpio_init() inicializa un pin GPIO. 
    Esta función debe ser llamada en cada pin antes de 
    configurarlo para entrada o salida.*/

    gpio_init(LED_lavar);
    gpio_init(LED_enjuagar);
    gpio_init(LED_centrifugar);
    gpio_init(BOTON_2);

    /* Estas llamadas a gpio_set_dir() configuran la dirección
    de cada pin. Los pines conectados a los LEDs se configuran 
    como salidas (GPIO_OUT), y el pin conectado al botón se 
    configura como entrada (GPIO_IN) .*/

    gpio_set_dir(LED_lavar, GPIO_OUT);
    gpio_set_dir(LED_enjuagar, GPIO_OUT);
    gpio_set_dir(LED_centrifugar, GPIO_OUT);
    gpio_set_dir(BOTON_2, GPIO_IN);

    /* La función 'gpio_pull_up(pin)' es utilizada para activar
    la resistencia de pull-up interna para un pin GPIO específico*/

    gpio_pull_up(BOTON_2);
    gpio_put(LED_lavar, false);
    gpio_put(LED_enjuagar,false);
    gpio_put(LED_centrifugar, false);
}

int tipo_de_lavado_(){
    
        if (!gpio_get(BOTON_2)) {
            led_state_2++;
            zumbador(1);
            
            if (led_state_2 > 6)
            {
                led_state_2 = 0;
            }
            send_cmd(led_state_2, 0x6b);
            gpio_put(LED_lavar, (led_state_2 == 0 || led_state_2 == 3 || led_state_2 == 4 || led_state_2 == 6));
            gpio_put(LED_enjuagar, led_state_2 == 1 || led_state_2 == 3 || led_state_2 == 5 || led_state_2 == 6);
            gpio_put(LED_centrifugar, led_state_2 == 2 || led_state_2 == 4 || led_state_2 == 5 || led_state_2 == 6);
    }

    return led_state_2;
}


