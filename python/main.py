from machine import UART, Pin, I2C
from utime import sleep
from ssd1306 import SSD1306_I2C

def main() -> None:
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
                print(cmd_val)
                # Apagado encendido 
                if cmd_val >= 0x61 and cmd_val < 0x63:
                    pass
                # Inicio pausa
                elif cmd_val < 0x65:
                    pass
                # Ciclo-lavado
                elif cmd_val < 0x68:
                    pass
                # Nivel de agua
                elif cmd_val < 0x6B:
                    pass
                # Tipo lavado
                else:
                    pass
                

main()
