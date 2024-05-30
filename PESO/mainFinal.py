from machine import Pin, I2C
import utime
from hx711 import HX711

# Configuración de pines
DOUT_PIN_NUMBER = 14  # Número de pin del HX711 (GP14)
SCK_PIN_NUMBER = 15   # Número de pin del reloj del HX711 (GP15)

# Configuración del sensor HX711
hx = HX711(d_out=DOUT_PIN_NUMBER, pd_sck=SCK_PIN_NUMBER)

# Ajuste manual de las lecturas del sensor (ajustar según sea necesario)
SENSOR_OFFSET = 0  # Compensación de offset
SENSOR_SCALE = 1  # Factor de escala

# Umbral para el nivel bajo
UMBRAL_BAJO = 500

def adjust_reading(raw_reading):
    #Ajusta manualmente la lectura del sensor.
    return (raw_reading + SENSOR_OFFSET) * SENSOR_SCALE

def read_weight():
    #Lee el peso del sensor HX711 y lo devuelve.
    raw_reading = hx.read()
    adjusted_reading = adjust_reading(raw_reading)
    return adjusted_reading

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

def loop():
    """
    Realiza la lectura del peso cada cierto intervalo de tiempo.
    """
    while True:
        print("Iniciando lectura de peso...")
        weight = read_weight()
        level = classify_level(weight)
        print("Nivel de agua:", level)
        time.sleep(5)  # Espera 5 segundos antes de realizar la próxima lectura


if __name__ == "__main__":
    setup()
    loop()