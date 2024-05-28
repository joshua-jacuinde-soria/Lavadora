import network
import time
from time import sleep, sleep_us, ticks_us
from machine import Pin, ADC
from simple import *
import dht
import BlynkLib

# Configuración del broker MQTT
MQTT_SERVER = '192.168.1.74'
MQTT_PORT = 1883
#MQTT_TOPIC_peso = 'sensors/peso'
MQTT_TOPIC_ultra_L = 'sensors/ultraL'
MQTT_TOPIC_ultra_D = 'sensors/ultraD'
MQTT_TOPIC_agua = 'sensors/agua'
client = MQTTClient('Raspberrry_Pi_Pico_W', MQTT_SERVER, port=MQTT_PORT)

def read_peso():
    # Aqui va todo lo relacionado al sensor de peso
    return 0

def read_ultra():
    # Aqui va todo lo relacionado al sesnor ultrasonico
    trig = Pin(17, Pin.OUT)
    echo = Pin(16, Pin.IN, Pin.PULL_DOWN)
    trig.value(0)
    sleep(0.1)
    trig.value(1)
    sleep_us(2)
    trig.value(0)
    while echo.value()==0:
        pulse_start = ticks_us()
    while echo.value()==1:
        pulse_end = ticks_us()
    pulse_duration = float(pulse_end) - float(pulse_start)
    distance = pulse_duration * 17165 / 1000000
    distance = round(distance, 0)
    if distance < 20:
        level = 0
    elif distance >= 20 and distance < 100:
        level = 1
    elif distance >= 100 and distance < 200:
        level = 2
    elif distance >= 200 and distance < 300:
        level = 3
    else:
        level = 4
    return level, distance

def read_agua():
    # Aqui va todo lo relacionado al sensor del agua
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
        """peso = read_peso()
        print('Peso: ', peso)
        client.publish(MQTT_TOPIC_peso, str(peso))"""

        level, distance = read_ultra()
        print('Nivel: ', level)
        client.publish(MQTT_TOPIC_ultra_L, str(level))

        print('Distancia: ', distance)
        client.publish(MQTT_TOPIC_ultra_D, str(distance))
        
        agua = read_agua()
        print('Agua: ', agua)
        client.publish(MQTT_TOPIC_agua, str(agua))
        
        # Tiempo de espera
        time.sleep(5)

        # Send sensor data to Blynk
        #blynk.virtual_write(0, peso)  # virtual pin 0 for peso
        blynk.virtual_write(1, level)    # virtual pin 1 for nivel
        blynk.virtual_write(2, distance)   # virtual pin 2 for distancia
        blynk.virtual_write(3, agua)   # virtual pin 2 for distancia

        # Run Blynk
        blynk.run()

def conecction_wifi()->None:
    # Configuración de la red Wi-Fi
    #SSID = 'INFINITUM6832_2.4'
    #PASSWORD = 'XnCjzCT8id'
    SSID = 'labred'
    PASSWORD = 'labred2017'
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