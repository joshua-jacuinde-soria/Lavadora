# Ciclo de Lavado

El presente documento describe el funcionamiento de el ciclo de lavado junto con las guías para conectar los componentes necesarios que se requieren conectar al microcontrolador.

# Funcion

```
int cicloLavado(int cycleStatus) {
    cycleStatus++;
    if (cycleStatus > 2) {
        cycleStatus = 0;
    }
    gpio_put(LED_SUAVE, cycleStatus == 0);
    gpio_put(LED_PESADO, cycleStatus == 1);
    gpio_put(LED_RAPIDO, cycleStatus == 2);

    return cycleStatus;
}
```

Esta funcion tiene como argumento `cycleStatus` un entero que representa el estado del ciclo de lavado, tenemos tres estados/ciclos, estos estados van de 0 a 2 que son:

0.   Ciclo Suave
1.   Ciclo Pesado
2.   Ciclo Rapido

La logica de esta funcion tiene la siguiente estructura:

-   Inicio de funcion:
    -   Por cada vez que se invoque esta funcion significa que el boton fue presionado, por lo que tenemos que actualizar el estado al si`uiente
    `cycleStatus++'
-   Verificar que el estado se encuentre dentro de los limites:
    - Por lo que si al momento de llamar la funcion el estado es 2, tenemos que volver al primer estado.
    ```
    if (cycleStatus > 2) {
    cycleStatus = 0;
    }
    ```
-   Prender los LEDS asociados al estado correspondiente:
    -   Cada LED le corresponde un ciclo:

    |   Ciclo	|   Led	|
    |---	|---	|
    |   0 - Suave  |   GPIO 4  |
    |   1 - Pesado |   GPIO 5  |
    |   2 - Rapido |   GPIO 6  |

    - La logica encargada de este encendido de LEDS de acuerdo al ciclo pudo ser abordado con una estructura if, pero por el uso de buenas practicas se opto por verificar si el estado es igual dentro de la funcion encargada de prender cada led por ejemplo:
    ```
    gpio_put(LED_SUAVE, cycleStatus == 0)
    ```
    - Si el ciclo es cero, la funcion da verdadera y regresa un 1, que para gpio_put significaria que prenda el led, de no ser asi, el led se apaga.
    - Cada led tiene una funcion gpio_put por lo que de esta manera tenemos la logica para el cambio de ciclo

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