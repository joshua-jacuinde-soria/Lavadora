# Tipo de lavado

Este documento tiene como objetivo proporcionar una descripción detallada de la implementación y funcionalidad de los archivos de programación responsables de controlar los diferentes tipos de lavado en el tablero de  una lavadora. El sistema está diseñado para mostrar graficamente por medio de tres leds y un boton la representacion de las tres operaciones esenciales: lavado, enjuagado y centrifugado.

# Lista de materiales

A continuación se muestran los materiales que son necesarios para poder realizar el proyecto.

|   Material a Usar	|   Cantidad	|
|---	|---	|
|    Led	|  3 	|
|    Resistencias  (220Ω)	|   3	|
|    Mini botón	|   1	|
|    Jumpers    |   5    |

# Tabla de conexiones

En la siguiente tabla se muestran las conexiones que se tienen que hacer desde los puertos de la Raspberri Pi Pico W hacia los compenentes que sean requeridos.

|   Puerto GPIO	|   Salida	|
|---	|---	|
|   8    |    led (lavado)	|
|   9	|    led (enjuagado)	|
|   10	|    led (centrifugado)	|
|   11	|    botón	|
