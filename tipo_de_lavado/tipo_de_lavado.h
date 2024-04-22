#include "hardware/gpio.h"

/* Aquí se definen constantes para los números de pin de 
los GPIOs a los que están conectados los LEDs y el botón. */ 

const uint LED_lavar = 8;           // Led para lavar
const uint LED_enjuagar = 9;        // Led para enjuagar
const uint LED_centrifugar = 10;    // Led para centrifugar
const uint BOTON = 11;              // Botón de acción

/* La siguiente función va a permitir retornar al usuario
un valor entero para poder asociarlo con alguna acción 
referente al tipo de lavado de un tablero de lavadora */

int tipo_lavado (int estado){
    /*Se recibe un estado de valor entero, dependiendo
    del número que se reciba se tiene que trabajar con el */
    estado++;
    
    /*Si el estado es mayor a seis(porque solo hay siete 
    posibles tipos de lavado), se tiene que reiniciar el 
    estado a cero. */
    if (estado > 6)
    {
        estado = 0;
    }
    /*Dependiendo de la entrada que se tenga, podremos
    definir en que tipo de lavadoe está el usuarioo actualmente*/
    gpio_put(LED_lavar, (estado == 0 || estado == 3 || estado == 4 || estado == 6));
    gpio_put(LED_enjuagar, estado == 1 || estado == 3 || estado == 5 || estado == 6);
    gpio_put(LED_centrifugar, estado == 2 || estado == 4 || estado == 5 || estado == 6);

    return estado;
}