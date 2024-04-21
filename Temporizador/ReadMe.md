# Comentarios Generales:
-Este programa es un temporizador simple que cuenta hacia abajo desde 60 segundos

-Utiliza dos displays de 7 segmentos para mostrar los minutos y segundos restantes.

-Un botón se utiliza para iniciar y pausar el temporizador.

# Librerías Utilizadas:
<stdio.h>: Librería estándar para entrada y salida estándar.

"pico/stdlib.h": Librería Pico SDK para inicialización de hardware y funciones estándar.

"hardware/gpio.h": Librería Pico SDK para control de GPIO.

<stdbool.h>: Librería estándar para el uso de tipos de datos booleanos.

# Definiciones de Constantes:
FIRST_GPIO_DISPLAY1 y FIRST_GPIO_DISPLAY2: Define los primeros pines GPIO utilizados para controlar los displays de 7 segmentos.

BUTTON_GPIO: Define el pin GPIO utilizado para el botón.
Arreglos de Bits:

bits[10]: Contiene los patrones de bits para representar los números del 0 al 9 en un display de 7 segmentos.
common[2]: Define los bits para el ánodo común de los displays de 7 segmentos.

# Funciones:
reconocer(int numero)

Esta función recibe un número entero entre 0 y 9 como argumento y devuelve el patrón de bits correspondiente para representar ese número en un display de 7 segmentos. El valor devuelto es un entero que representa los segmentos que deben encenderse para mostrar el número en el display.

mostrar(int decenas, int unidades)

Esta función muestra dos dígitos en un display de 7 segmentos, uno para las decenas y otro para las unidades. Recibe dos enteros: decenas y unidades, que representan los valores que se mostrarán en el display. Utiliza la función reconocer() para obtener los patrones de bits correspondientes a los números proporcionados y luego enciende los segmentos necesarios en los displays.

pausa(int estado)

Esta función se utiliza para alternar entre dos estados: pausa y ejecución del temporizador. Recibe un entero estado que representa el estado actual del temporizador (1 para pausa y 2 para ejecución). Devuelve el nuevo estado después de alternarlo.

# Función main():
Inicializa los pines GPIO para los displays de 7 segmentos y el botón.

Declara variables para el temporizador, el estado del botón y el estado de pausa.

En un bucle infinito:
Lee el estado del botón.
Si se detecta un cambio de estado del botón, alterna entre pausa y ejecución del temporizador.
Si el temporizador está en pausa, muestra el tiempo restante y espera a que se presione el botón para reanudar.

Si el temporizador está en ejecución, cuenta hacia abajo el tiempo restante.
El temporizador se detiene cuando el tiempo alcanza 0:00.
Detalles de Implementación:
La función mostrar() utiliza los patrones de bits definidos en bits[] para mostrar los números en los displays de 7 segmentos.
Los displays de 7 segmentos se actualizan continuamente dentro del bucle principal.
El temporizador se actualiza cada 50 ms para evitar el rebote del botón y mantener una respuesta rápida del sistema.