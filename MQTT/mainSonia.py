from machine import Pin, I2C
import utime
import ssd1306
from hx711 import HX711

# Configuración de pines
DOUT_PIN_NUMBER = 14  # Número de pin del HX711 (GP14)
SCK_PIN_NUMBER = 15   # Número de pin del reloj del HX711 (GP15)
BUTTON_PIN_NUMBER = 16  # Número de pin del botón (GP16)

# Configuración de la pantalla OLED
WIDTH = 128
HEIGHT = 64
i2c = I2C(0, scl=Pin(9), sda=Pin(8), freq=400000)  # Pins SDA (GP8) y SCL (GP9)
oled = ssd1306.SSD1306_I2C(WIDTH, HEIGHT, i2c)

# Configuración del sensor HX711
hx = HX711(d_out=DOUT_PIN_NUMBER, pd_sck=SCK_PIN_NUMBER)

# Ajuste manual de las lecturas del sensor (ajustar según sea necesario)
SENSOR_OFFSET = 0  # Compensación de offset
SENSOR_SCALE = 1  # Factor de escala

# Umbral para el nivel bajo
UMBRAL_BAJO = 500

# Definir el botón como una variable global
button = Pin(BUTTON_PIN_NUMBER, Pin.IN, Pin.PULL_UP)

def adjust_reading(raw_reading):
    """
    Ajusta manualmente la lectura del sensor.
    """
    return (raw_reading + SENSOR_OFFSET) * SENSOR_SCALE

def read_weight():
    """
    Lee el peso del sensor HX711 y lo devuelve.
    """
    raw_reading = hx.read()
    adjusted_reading = adjust_reading(raw_reading)
    return adjusted_reading

def display_weight(weight):
    """
    Muestra el peso en la pantalla OLED.
    """
    oled.fill(0)
    oled.text("Peso:", 0, 0)
    ml = int(weight)
    ml = max(0, min(900, ml))  # Limitar el valor entre 0 y 900 ml
    oled.text("{:d} ml".format(ml), 0, 16)
    oled.show()
    print("Peso: {} ml".format(ml))

def classify_level(weight):
    """
    Clasifica el nivel de líquido según el peso.
    """
    if weight < UMBRAL_BAJO:
        return "Nivel bajo"
    elif weight == UMBRAL_BAJO:
        return "Nivel medio"
    else:
        return "Nivel alto"

def setup():
    """
    Configura el botón como entrada.
    """
    print("Listo para pesar (presiona el botón para iniciar)")

def loop():
    """
    Espera hasta que se presione el botón y luego realiza la lectura del peso.
    """
    while True:
        if not button.value():
            print("Iniciando lectura de peso...")
            weight = read_weight()
            display_weight(weight)
            level = classify_level(weight)
            print("Nivel de agua:", level)
            utime.sleep(0.1)  # Pequeño retardo para evitar rebotes del botón
            while not button.value():
                pass  # Espera hasta que el botón se suelte
            print("Presiona el boton para iniciar una nueva lectura")
        utime.sleep(0.1)  # Pequeño retardo antes de verificar el botón nuevamente

if __name__ == "__main__":
    setup()
    loop()
