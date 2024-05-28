// Se añaden las directivas
#ifndef tipo_lavado
#define tipo_lavado


// Importamos las librerias necesarias para poder trabajar
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../zumbador/zumbador.h"
#include "../uart/uart.h"

/* Aquí se definen constantes para los números de pin de 
los GPIOs a los que están conectados los LEDs y el botón. */ 

const uint LED_lavar = 8;           // Led para lavar
const uint LED_enjuagar = 9;        // Led para enjuagar
const uint LED_centrifugar = 10;    // Led para centrifugar
const uint BOTON_2 = 11;              // Botón de acción

void declara_inicializa(){
    stdio_init_all();

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
}

int tipo_de_lavado_(){
    int led_state = 6;
    
    //while (true) {
        if (!gpio_get(BOTON_2)) {
            led_state++;
            zumbador(1);
            
            if (led_state > 6)
            {
                led_state = 0;
            }
            // Enviar el comando al receptor
            send_cmd(led_state, 0x6b);
            gpio_put(LED_lavar, (led_state == 0 || led_state == 3 || led_state == 4 || led_state == 6));
            gpio_put(LED_enjuagar, led_state == 1 || led_state == 3 || led_state == 5 || led_state == 6);
            gpio_put(LED_centrifugar, led_state == 2 || led_state == 4 || led_state == 5 || led_state == 6);
        //}
        //sleep_ms(200);
    }

    return led_state;
}

#endif