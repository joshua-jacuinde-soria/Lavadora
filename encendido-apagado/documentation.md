# Encendido apagado

El presente documento describe el funcionamiento de el ciclo de lavado junto con las guías para conectar los componentes necesarios que se requieren conectar al microcontrolador.

# Funcion

```
int encendidoApagado (int estado) {
    estado = !estado;
    gpio_put(LED, estado);
    return estado;
}
```

Esta funcion tiene como argumento `estado` un entero que representa el estado [apagado, encendido] que se representan con [0, 1] respectivamente:

La logica de esta funcion tiene la siguiente estructura:

-   Inicio de funcion:
    -   Por cada vez que se invoque esta funcion significa que el boton fue presionado, por lo que tenemos que actualizar el estado negado del actual
-   Prender/Apagar el LED de con el estado asociado estado:
    ```
    gpio_put(LED, estado)
    ```

# Lista de materiales

|   Item	|   Cantidad	|
|---	|---	|
|   led	|  1 	|
|   resistencia <sub>al menos 200 ohms</sub>	|   1	|
|   botón	|   1	|
|   M/M cables jumper    |   3    |

# Tabla de conexiones
|   Puerto GPIO	|   Componente	|
|---	|---	|
|   28    |   led	|
|   27	|   botón	|

 > El botón deberá de ir conectado a gnd