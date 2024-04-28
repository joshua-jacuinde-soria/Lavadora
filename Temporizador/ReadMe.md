# Directivas de Preprocesador:

#ifndef VISUALIZADOR_H: Directiva de preprocesador que evita la inclusión múltiple del archivo Visualizador.h.

#define VISUALIZADOR_H: Directiva de preprocesador que define el identificador VISUALIZADOR_H para evitar la inclusión múltiple del archivo Visualizador.h.

# Inclusión de Librerías:

#include <stdio.h>: Inclusión de la librería estándar de entrada y salida para funciones de entrada y salida.

#include "pico/stdlib.h": Inclusión de la librería pico/stdlib.h que proporciona funciones y macros específicas para el microcontrolador Pico.

#include "hardware/gpio.h": Inclusión de la librería hardware/gpio.h para el manejo de GPIOs (General Purpose Input/Output).

#include <stdbool.h>: Inclusión de la librería estándar de C que define el tipo de datos booleano y sus valores true y false.

# Definiciones de Constantes:
FIRST_GPIO_DISPLAY1: Define el primer GPIO utilizado para el primer display de 7 segmentos.

FIRST_GPIO_DISPLAY2: Define el primer GPIO utilizado para el segundo display de 7 segmentos.

BUTTON_GPIO: Define el GPIO utilizado para el botón de control.

# Variables Globales:
int decena: Almacena el valor de las decenas a mostrar en el visualizador.

int unidad: Almacena el valor de las unidades a mostrar en el visualizador.

int estado_2: Almacena el estado actual del botón de pausa.

bool ultimo_estado_boton: Almacena el último estado del botón.

bool boton_presionado: Indica si el botón está actualmente presionado.

int bits[11]: Array que contiene los patrones de bits para representar los números del 0 al 9 en un display de 7 segmentos.

int common[2]: Array que contiene los valores para el ánodo común de los displays.

# Funciones:
void mostrar(int decenas, int unidades): Función que muestra en el visualizador los dígitos de decenas y unidades pasados como parámetros.

void inicio_visualizador(): Función que inicializa los GPIOs para los displays y el botón.

int pausa_vis(): Función que gestiona el estado del botón de pausa y devuelve el estado actual.

int visualizador(int valor, int pausa): Función principal que controla el visualizador, mostrando los valores proporcionados y gestionando la pausa según el estado del botón.

# Descripcion

# Función void mostrar(int decenas, int unidades)
Esta función se encarga de mostrar en el visualizador de dos dígitos de 7 segmentos los valores de decenas y unidades proporcionados como parámetros.

Parámetros:
decenas: Valor entero que representa las decenas a mostrar en el visualizador.
unidades: Valor entero que representa las unidades a mostrar en el visualizador.

Comportamiento:
Calcula los patrones de bits correspondientes para representar los dígitos de decenas y unidades en el visualizador.

Utiliza la función gpio_set_mask() para enviar los patrones de bits a los GPIOs asociados con los displays.

Alterna entre los displays de decenas y unidades para mostrar los dígitos de manera secuencial.

Retorno: La función no retorna ningún valor.

# Función void inicio_visualizador()
Esta función se encarga de inicializar los GPIOs utilizados para controlar los displays de 7 segmentos y el botón de pausa.

Comportamiento:
Utiliza un bucle for para inicializar los GPIOs asociados con los displays de 7 segmentos.

Configura los GPIOs como salidas y establece la polaridad de salida invertida para los displays.

Inicializa el GPIO asociado con el botón de pausa como una entrada y habilita la resistencia pull-up interna.

Retorno: La función no retorna ningún valor.

# Función int pausa_vis()

Esta función gestiona el estado del botón de pausa y devuelve el estado actual.

Comportamiento:
Verifica si el botón de pausa está presionado usando gpio_get(BUTTON_GPIO).

Incrementa el estado estado_2 si el botón está presionado y emite un zumbido usando la función zumbador().

Limita el valor de estado_2 a 1 o 2.

Retorna el estado actual del botón de pausa.

Retorno: Devuelve un entero que indica el estado actual del botón de pausa (1 o 2).

# Función int visualizador(int valor, int pausa)
Esta función controla el visualizador, mostrando los valores proporcionados y gestionando la pausa según el estado del botón.

Parámetros:
valor: Valor entero que se va a mostrar en el visualizador.

pausa: Valor entero que indica si se debe pausar la visualización.

Comportamiento:
Calcula las decenas basándose en el valor proporcionado.

Si se solicita pausa, muestra secuencialmente los dígitos de decenas y unidades hasta que se reanude la visualización.

Utiliza la función mostrar() para mostrar los dígitos en el visualizador.

Retorno: La función siempre retorna 0.

Estas funciones proporcionan la lógica necesaria para controlar el visualizador de dos dígitos de 7 segmentos y gestionar la pausa mediante el botón asociado.