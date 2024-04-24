
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

    while (true)
    {
        if(encendido_Apagado()){
            nivel_agua();
            if (tipo_de_lavado_() == 0 || tipo_de_lavado_() == 1 || tipo_de_lavado_() == 2)
            {
                visualizador(cicloLavado());
                zumbador(2);
            }
            
        //     if (tipo_de_lavado_() == (0,1,2))
        //     {
        //     }
        //     else if (tipo_de_lavado_() == (3,4,5))
        //     {
        //         for (int i = 0; i < 2; i++)
        //         {
        //             visualizador(cicloLavado());
        //             zumbador(2);
        //         }
        //     }
        //     else
        //     {
        //         for (int i = 0; i < 3; i++)
        //         {
        //             visualizador(cicloLavado());
        //             zumbador(2);
        //         }
        //     }
        }
        else
        {
            inicio_nivelagua();
            inicio_tipolavado();
        }
        
                
        sleep_ms(50); 
    }
}

