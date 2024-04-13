@ directivas de ensamble (los programas inician con estas instrucciones)
.text @ Guardar las instrucciones en la seccion de codigo
.align 1 @ Indica que el codigo ocupa direcciones de 2^1 Byte
.global main @ Permite que el procedimiento pueda llamarse
.syntax unified @ Usa la sintaxis nueva de ARM thumb
.thumb_func @ Indica que las intrucciones de la funcion son 2 Bytes
@ Define constants
.equ LED_SUAVE, 4
.equ LED_PESADO, 5
.equ LED_RAPIDO, 6
.equ BUTTON_CYCLE, 7
.equ GPIO_OUT, 1
.equ GPIO_IN, 0
main:
    @ Prologue
    push    {r7, lr}    @ Respaldar apuntador de marco y registro de enlace
    sub     sp, sp, 8   @ Reservar espacio para variables locales 
    add     r7, sp      @ Crear apuntador de marco 