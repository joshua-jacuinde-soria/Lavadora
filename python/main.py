from machine import UART, Pin, I2C
from utime import sleep
from ssd1306 import SSD1306_I2C
import shared_obj
from MQTT_Final import init_dashboard, print_and_publish

def nivel_agua(state: int) -> None:
    """Function that will update the leds based on the water level.

    Args:
        state (int): Water level state.
    """
    if state == 0:
        print("Encendiendo led 1")
        shared_obj.led_1.value(1)
        shared_obj.led_2.value(0)
        shared_obj.led_3.value(0)
    elif state == 1:
        print("Encendiendo led 2")
        shared_obj.led_1.value(0)
        shared_obj.led_2.value(1)
        shared_obj.led_3.value(0)
    else:
        print("Encendiendo led 3")
        shared_obj.led_1.value(0)
        shared_obj.led_2.value(0)
        shared_obj.led_3.value(1)
    
def verificar_encendido() -> None:
    if shared_obj.state_encendido == False:
    # Apaga todos los leds
        shared_obj.led_1.value(0)
        shared_obj.led_2.value(0)
        shared_obj.led_3.value(0)
    
    
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
    # init Dhasboard
    blynk = init_dashboard()
    print("Sali del init")
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
                print("Command received: ", cmd_val)
                verificar_encendido()
                state_machine(cmd_val)
        # Si no hay que leer datos de la Raspberry
        print_and_publish(blynk)
        sleep(0.1)
        continue

if __name__ == "__main__":
    main()
