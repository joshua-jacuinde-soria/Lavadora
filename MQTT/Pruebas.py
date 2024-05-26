import network
import time
from machine import Pin, ADC
from simple import *
import dht

# Configurar el pin GPIO para el DHT22 (GP11 en este ejemplo)
dht_pin = Pin(11)
sensor = dht.DHT22(dht_pin)

# Configuración de la red Wi-Fi
SSID = 'INFINITUM6832_2.4'
PASSWORD = 'XnCjzCT8id'

# Conectar a Wi-Fi
wlan = network.WLAN(network.STA_IF)
wlan.active(True)
try:
    wlan.connect(SSID, PASSWORD)
except OSError as error:
    print(f'error is {error}')

# Esperar la conexión WiFi
max_attempts = 10
attempt = 0
while not wlan.isconnected() and attempt < max_attempts:
    print('Intentando conectar a WiFi...')
    time.sleep(1)
    attempt += 1

if wlan.isconnected():
    print('Conexión WiFi establecida, IP:', wlan.ifconfig()[0])
else:
    print('Error: No se pudo conectar a la red WiFi')
    raise RuntimeError('No se pudo conectar a la red WiFi')

print('Conexión WiFi establecida, IP:', wlan.ifconfig()[0])

# Configuración del broker MQTT
MQTT_SERVER = '192.168.1.74'
MQTT_PORT = 1883
MQTT_TOPIC_luz = 'sensors/luz'
MQTT_TOPIC_DHT1 = 'sensors/temp'
MQTT_TOPIC_DHT2 = 'sensors/hum'

client = MQTTClient('LA_SONORA_DINAMITA', MQTT_SERVER, port=MQTT_PORT)

# Conectar al broker MQTT
client.connect()

# Configuración del termoresistor
thermistor_pin = ADC(Pin(26))

def read_temperature():
    # Aquí deberías poner la fórmula para convertir la lectura del ADC en grados Celsius
    raw_value = thermistor_pin.read_u16()
    voltage = raw_value * (3.3 / 65535)
    temperature = voltage
    return temperature

def read_DHTT22_Temp():
    # Prueba para leer datos del DHT22 conectado a la Raspberry Pi Pico W 
    try:
        sensor.measure()
        temp = sensor.temperature()
        hum = sensor.humidity()
        return temp, hum
    except OSError as e:
        print("Error al leer el sensor:", e)
        return None, None
    
def read_and_publish():
    while True:
        temperature = read_temperature()
        print('Luz_T: ', temperature)
        client.publish(MQTT_TOPIC_luz, str(temperature))

        #time.sleep(5)
        DHT_T, DHT_H = read_DHTT22_Temp()
        print('DHT1: ', DHT_T)
        client.publish(MQTT_TOPIC_DHT1, str(DHT_T))
        
        print('DHT2: ', DHT_H)
        client.publish(MQTT_TOPIC_DHT2, str(DHT_H))
        time.sleep(5)


read_and_publish()