#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdbool.h>

#include "../ciclo-de-lavado/cicloLavado.h"
#include "../encendido-apagado/encendidoApagado.h"
#include "../Temporizador/tempotizadorBoton.h"
#include "../tipo_de_lavado/tipo_lavado.h"
#include "../NivelAgua/NivelAgua.h"
#include "../zumbador/zumbador.h"
#include "../uart/uart.h"

int main(){
    stdio_init_all();

    inicio_cicloLavado();
    inicio_encendidoApagado();
    inicio_nivelagua();
    declara_inicializa();
    inicio_visualizador();
    inicio_zumbador();
    inicio_uart();
    int ciclo;
    int pausa_;

    while (true)
    {
        if(encendidoApagado()){
            nivel_agua();
            ciclo = cicloLavado();

            if (tipo_de_lavado_() == 0 || tipo_de_lavado_() == 1 || tipo_de_lavado_() == 2)
            {
                pausa_ = pausa_vis();
                visualizador(ciclo, pausa_);
                estado_2 = 0;
            }
            else if (tipo_de_lavado_() == 3 || tipo_de_lavado_() == 4 || tipo_de_lavado_() == 5)
            {
                pausa_ = pausa_vis();
                visualizador(ciclo, pausa_);
                estado_2 = 0;
                visualizador(ciclo, pausa_);
                estado_2 = 0;
            }
            else
            {
                pausa_ = pausa_vis();
                visualizador(ciclo, pausa_);
                estado_2 = 0;
                visualizador(ciclo, pausa_);
                estado_2 = 0;
                visualizador(ciclo, pausa_);
                estado_2 = 0;
            }
            
            
        }
        else
        {
            inicio_nivelagua();
            declara_inicializa();
            inicio_cicloLavado();
            inicio_visualizador();
        }
        
                
        sleep_ms(50); 
    }
}
