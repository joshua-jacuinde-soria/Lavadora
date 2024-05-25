# Implementación de DashBoard por medio del protocolo MQTT

# `Introducción`
Este programa se encargará de leer los valores de los sensores que estén conectados al microcontrolador "Raspberry Pi Pico W" mediante el protocólo MQTT y se mostrarán en un Dashboard.

- `encendidoApagado.h`: Función para encender y apagar la lavadora.
- `hello_7segment.h`: Función para mostrar mensajes en un display de 7 segmentos.
- `tipo_de_lavado.h`: Función para seleccionar el tipo de lavado.
- `cicloLavado.h`: Función para ejecutar el ciclo de lavado.
- `zumbador.h`: Función para activar el zumbador de la lavadora.

## Funcionamiento

El programa sigue estos pasos:

1. Verifica si la lavadora está encendida.
2. Selecciona el tipo de lavado.
3. Ejecuta el ciclo de lavado según el tipo seleccionado, mostrando información en el display y activando el zumbador.

## Conexiones.