# Descripción del Código

Este código está diseñado para generar un sonido utilizando un zumbador conectado a un microcontrolador Raspberry Pi Pico. El sonido producido sigue un patrón específico para simular sonidos variados según la selección lo necesite. Además, esta es un añadido de funcionalidad para un panel de lavadora. Su función es que cada vez que se seleccione alguna funcion esta emita un sonido, al terminar algun ciclo suene de forma diferente, etc.

## Funcionamiento

El código utiliza dos arreglos para controlar el patrón de sonido y los tiempos de reproducción:

- El arreglo `sonidos` contiene los valores binarios (0 o 1) que representan el estado del zumbador en cada paso del sonido.
- El arreglo `tiempos` define la duración en milisegundos de cada paso del sonido.

El ciclo principal del programa verifica constantemente que opción ah sido seleccionada para que segun esta se emita un sonido en el zumbador. Cuando se detecta la selección, el código activa el zumbador para reproducir el patrón de sonido definido en los arreglos. Esto se logra mediante la activación y desactivación del zumbador según el patrón de sonido y los tiempos definidos.

## Configuración de Pines

- El zumbador está conectado al pin GPIO 16 (`Zumbador`).
- El botón está conectado al pin GPIO 0 (`boton`).

## Requisitos

- Placa Raspberry Pi Pico.
- Conexión correcta del zumbador y el botón a los pines GPIO definidos en el código.
- Entorno de desarrollo compatible con C para compilar y cargar el código en la placa.

## Uso

1. Configura tu entorno de desarrollo y asegúrate de tener los drivers y herramientas necesarias para programar la Raspberry Pi Pico.
2. Conecta el zumbador y el botón según las especificaciones de pines definidas en el código.
3. Compila y carga el código en la Raspberry Pi Pico.
4. Ejecuta el programa y presiona el botón para escuchar el sonido generado que simula una moneda en el juego Mario Bros.

## Notas

- Puedes ajustar los valores en los arreglos `sonidos` y `tiempos` para modificar el patrón de sonido y la duración de cada paso según tus preferencias.
- Asegúrate de seguir las medidas de seguridad al manipular componentes electrónicos y al utilizar la Raspberry Pi Pico.

¡Disfruta del sonido de la moneda de Mario Bros generado por tu Raspberry Pi Pico!
