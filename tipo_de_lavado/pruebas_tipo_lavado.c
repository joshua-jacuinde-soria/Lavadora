#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "tipo_de_lavado.h"

#define LED_lavar  8           // Led para lavar
#define LED_enjuagar  9        // Led para enjuagar
#define LED_centrifugar  10    // Led para centrifugar
#define BOTON  11              // Botón de acción

int main (){

    stdio_init_all();

    /* Cada llamada a gpio_init() inicializa un pin GPIO. 
    Esta función debe ser llamada en cada pin antes de 
    configurarlo para entrada o salida.*/

    gpio_init(LED_lavar);
    gpio_init(LED_enjuagar);
    gpio_init(LED_centrifugar);
    gpio_init(BOTON);

    /* Estas llamadas a gpio_set_dir() configuran la dirección
    de cada pin. Los pines conectados a los LEDs se configuran 
    como salidas (GPIO_OUT), y el pin conectado al botón se 
    configura como entrada (GPIO_IN) .*/

    gpio_set_dir(LED_lavar, GPIO_OUT);
    gpio_set_dir(LED_enjuagar, GPIO_OUT);
    gpio_set_dir(LED_centrifugar, GPIO_OUT);
    gpio_set_dir(BOTON, GPIO_IN);

    /* La función 'gpio_pull_up(pin)' es utilizada para activar
    la resistencia de pull-up interna para un pin GPIO específico*/

    gpio_pull_up(BOTON);

    /* Se inicializa el contador que enviará la señal del estado
    en el que este actualmente el tipo de lavado por medio del 
    boton. */
    int estado = 6;

    while (true) {
        if (!gpio_get(BOTON) == 1) {
            /*La siguiente instrucción manda a llamar a la 
            función "tipo_lavado" para que se realize el proceso
            de lectura de datos.*/
            estado = tipo_lavado(estado);
        }
        sleep_ms(200);
    }

    // pruebas_tipo_lavado.c :
    return (0);
}