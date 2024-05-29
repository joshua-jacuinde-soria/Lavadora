from machine import UART, Pin, I2C
from utime import sleep
from ssd1306 import SSD1306_I2C
import shared_obj

def init_leds() -> None:
    """Function that will initialize the leds.
    """
    for led in shared_obj.nivel_leds:
        Pin(led, Pin.OUT).value(0) # Turn off the led after initialization

def nivel_agua(state: int) -> None:
    """Function that will update the leds based on the water level.

    Args:
        state (int): Water level state.
    """
    if state == 0:
        shared_obj.nivel_leds[0] = 1
        shared_obj.nivel_leds[1] = 0
        shared_obj.nivel_leds[2] = 0
    elif state == 1:
        shared_obj.nivel_leds[0] = 0
        shared_obj.nivel_leds[1] = 1
        shared_obj.nivel_leds[2] = 0
    else:
        shared_obj.nivel_leds[0] = 0
        shared_obj.nivel_leds[1] = 0
        shared_obj.nivel_leds[2] = 1
    
    
def state_machine(cmd_val: int) -> None:
    """State machine for the washing machine. This function will update the state of the washing machine based on the command received.

    Args:
        cmd_val (int): Command value received from the UART.
    """    
    # Apagado encendido 
    if cmd_val >= 0x61 and cmd_val < 0x63:
        shared_obj.state_encendido = shared_obj.map_cmd[cmd_val]
    # Inicio pausa
    elif cmd_val < 0x65:
        shared_obj.state_pausa = shared_obj.map_cmd[cmd_val]
    # Ciclo-lavado
    elif cmd_val < 0x68:
        shared_obj.state_ciclo_lavado = shared_obj.map_cmd[cmd_val]
    # Nivel de agua
    elif cmd_val < 0x6B:
        shared_obj.state_nivel_agua = shared_obj.map_cmd[cmd_val]
        nivel_agua(cmd_val - 0x68)
    # Tipo lavado
    else:
        shared_obj.state_tipo_lavado = shared_obj.map_cmd[cmd_val]

def main() -> None:
    """Main function for the washing machine. This function will initialize the UART and read the commands from the UART.
    """
    # Before starting the state machine, we need to initialize the leds
    init_leds()
    # Initialize the UART
    uart = UART(0, baudrate=9600, tx=Pin(0), rx=Pin(1))
    while True:
        if uart.any():
            cmd = uart.read(1)
            try:
                cmd_val = ord(cmd)
            except TypeError:
                print("Invalid command")
                print(cmd)
            except:
                print("Unknown error")
                print(cmd)
            else:
                state_machine(cmd_val)


main()
