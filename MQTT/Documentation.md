# **Implementación de DashBoard por medio del protocolo MQTT**

## **Introducción**
Este programa es una extensión del proyecto del Tablero de Lavadora para la UEA de Microcontroladores. 
La función de este programa es encargarse de leer los valores de los sensores que estén conectados al microcontrolador "Raspberry Pi Pico W" mediante el protocólo MQTT y se mostrarán en un Dashboard, todo esto implementado en el lenguaje "MicroPhyton".

## Funciones y herramientas principales:

- `Mosquitto`: Eclipse Mosquitto es un corredor de mensajes de código abierto (EPL/EDL) que implementa las versiones de protocolo MQTT 5.0, 3.1.1 y 3.1.
- `simple.py`: Es una biblioteca que usaremos para poder hacer más simple la implementación del protocolo MQTT.
- `IoT MQTT Panel (Dashboard)`: Aplicación remota de Android para mostrar los valores mediante el protocolo MQTT.

## Funcionamiento

El programa sigue estos pasos:

1. Verifica si la lavadora está encendida.
2. Selecciona el tipo de lavado.
3. Ejecuta el ciclo de lavado según el tipo seleccionado, mostrando información en el display y activando el zumbador.

## Conexiones.
