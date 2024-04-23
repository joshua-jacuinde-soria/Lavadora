#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "tipo_de_lavado.h"

const uint LED_lavar = 8;           // Led para lavar
const uint LED_enjuagar = 9;        // Led para enjuagar
const uint LED_centrifugar = 10;    // Led para centrifugar
const uint BOTON = 11;              // Botón de acción