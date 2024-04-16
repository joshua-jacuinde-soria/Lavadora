# Ciclo de Lavado

El presente documento describe el funcionamiento de el ciclo de lavado junto con las guías para conectar los componentes necesarios que se requieren conectar al microcontrolador.

# Funcion

´´´
int cicloLavado(int cycleStatus)

´´´
Donde:
- cycleStatus

# Lista de materiales

|   Item	|   Cantidad	|
|---	|---	|
|   led	|  3 	|
|   resistencia <sub>al menos 200 ohms</sub>	|   3	|
|   botón	|   1	|
|   M/M cables jumper    |   5    |

# Tabla de conexiones
|   Puerto GPIO	|   Componente	|
|---	|---	|
|   4    |   led	|
|   5	|   led	|
|   6	|   led	|
|   7	|   botón	|

 > El botón deberá de ir conectado a gnd