
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdbool.h>

#include "cicloLavado.h"
#include "encendidoApagado.h"
#include "hello_7segment.h"
#include "tipo_de_lavado.h"
#include "NivelAgua.h"
#include "zumbador.h"

int main(){

    inicio_ciclolavado();
    inicio_encendidoApagado();
    inicio_nivelagua();
    inicio_tipolavado();
    inicio_visualizador();
    inicio_zumbador();
    int ciclo;
    int pausa_;
    
    while (true)
    {
        if(encendido_Apagado()){
            nivel_agua();
            ciclo = cicloLavado();

            if (tipo_de_lavado_() == 0 || tipo_de_lavado_() == 1 || tipo_de_lavado_() == 2)
            {
                pausa_ = pausa_vis();
                visualizador(ciclo, pausa_);
                zumbador(2);
            }
            
        }
        else
        {
            inicio_nivelagua();
            inicio_tipolavado();
            inicio_ciclolavado();
            inicio_visualizador();
        }
        
                
        sleep_ms(50); 
    }
}

