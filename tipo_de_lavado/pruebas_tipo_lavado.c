#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "tipo_de_lavado.h"

const uint LED_lavar = 8;           // Led para lavar
const uint LED_enjuagar = 9;        // Led para enjuagar
const uint LED_centrifugar = 10;    // Led para centrifugar
const uint BOTON = 11;              // Botón de acción

int main (){

    stdio_init_all();

    /* Cada llamada a gpio_init() inicializa un pin GPIO. 
    Esta función debe ser llamada en cada pin antes de 
    configurarlo para entrada o salida.*/

    gpio_init(LED_lavar);
    gpio_init(LED_enjuagar);
    gpio_init(LED_centrifugar);
    gpio_init(BOTON);

}