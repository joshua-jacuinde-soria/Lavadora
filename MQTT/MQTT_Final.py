import network
import time
from machine import Pin, ADC
from simple import *
import dht
import BlynkLib

# Configuración del broker MQTT
MQTT_SERVER = '192.168.1.74'
MQTT_PORT = 1883
MQTT_TOPIC_peso = 'sensors/peso'
MQTT_TOPIC_2 = 'sensors/2'
MQTT_TOPIC_3 = 'sensors/3'
client = MQTTClient('Raspberrry_Pi_Pico_W', MQTT_SERVER, port=MQTT_PORT)

def read_peso():
    # Aqui va todo lo relacionado al sensor de peso
    return 0

def read_2():
    # Aqui va todo lo relacionado al sensor 2
    return 0

def read_3():
    # Aqui va todo lo relacionado al sensor 3
    return 0

def read_and_publish():
    conecction_wifi()
    # Conectar al broker MQTT
    client.connect()

    # Blynk authentication token
    BLYNK_AUTH = "M0qTFY3EuM2lxZAFauuEvKw3W_SWSUZt"
    # Initialize Blynk
    blynk = BlynkLib.Blynk(BLYNK_AUTH)

    while True:
        peso = read_peso()
        print('Luz_T: ', peso)
        client.publish(MQTT_TOPIC_peso, str(peso))

        Sensor_2 = read_2()
        print('DHT1: ', Sensor_2)
        client.publish(MQTT_TOPIC_2, str(Sensor_2))
        
        Sensor_3 = read_3()
        print('DHT2: ', Sensor_3)
        client.publish(MQTT_TOPIC_3, str(Sensor_3))
        
        # Tiempo de espera
        time.sleep(5)

        # Send sensor data to Blynk
        blynk.virtual_write(0, peso)  # virtual pin 0 for peso
        blynk.virtual_write(1, Sensor_2)    # virtual pin 2 for Sensor 2
        blynk.virtual_write(2, Sensor_3)   # virtual pin 3 for Sensor 3

        # Run Blynk
        blynk.run()

def conecction_wifi()->None:
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

# Ojito aa la siguiente función, ver si se puede modificar
read_and_publish()