import network
import time
from time import sleep, sleep_us, ticks_us
from machine import Pin, ADC
from simple import *
import dht
import BlynkLib
from machine import Pin
from onewire import OneWire
from ds18x20 import DS18X20
import time
from python import shared_obj

# Configuración del broker MQTT
MQTT_SERVER = '172.18.63.63'
MQTT_PORT = 1883
#MQTT_TOPIC_peso = 'sensors/peso'
MQTT_TOPIC_ultra_L = 'sensors/ultraL' #14 y 15
MQTT_TOPIC_ultra_D = 'sensors/ultraD' #14 y 15
MQTT_TOPIC_tem = 'sensors/temp' # 16
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

class TempSensor:
    def __init__(self, pin: int) -> None:
        self.pin = Pin(pin)
        self.ds_sensor: DS18X20 = DS18X20(OneWire(self.pin))
        self.roms = self.ds_sensor.scan()
        print("Found DS devices: ", self.roms)

    def get_temp(self) -> float:
        self.ds_sensor.convert_temp()
        return self.ds_sensor.read_temp(self.roms[0])

def read_and_publish():
    conecction_wifi()
    # Conectar al broker MQTT
    client.connect()

    # Blynk authentication token
    BLYNK_AUTH = "M0qTFY3EuM2lxZAFauuEvKw3W_SWSUZt"
    
    # Initialize Blynk
    blynk = BlynkLib.Blynk(BLYNK_AUTH)

    while True:

        level, distance = 1, 2#read_ultra()
        print('Nivel: ', level)
        client.publish(MQTT_TOPIC_ultra_L, str(level))

        print('Distancia: ', distance)
        client.publish(MQTT_TOPIC_ultra_D, str(distance))
        
        # Descomentar test = TempSensor(16)
        temp = 3 #test.get_temp()
        print('Temp: ', temp)
        client.publish(MQTT_TOPIC_tem, str(temp))

        # Tiempo de espera para lectura de datos
        time.sleep(5)

        # Lectura de Datos de la Raspberry 
        # blynk.virtual_write(7, 2 )  # virtual pin 7 for 'Nivel de Leds' 
        blynk.virtual_write(8, shared_obj.state_pausa)  # virtual pin 8 for 'Pausa' 
        blynk.virtual_write(9, shared_obj.state_encendido)  # virtual pin 9 for 'Encendido/Apagado' 
        blynk.virtual_write(10, shared_obj.state_ciclo_lavado)  # virtual pin 10 for 'Ciclo de lavado'
        blynk.virtual_write(11, shared_obj.state_nivel_agua)  # virtual pin 11 for 'Nivel de Agua'
        blynk.virtual_write(12, shared_obj.state_tipo_lavado)  # virtual pin 12 for 'Tipo de lavado'

        # Send sensor data to Blynk
        #blynk.virtual_write(0, peso)  # virtual pin 0 for peso
        #blynk.virtual_write(1, level)    # virtual pin 1 for nivel
        #blynk.virtual_write(2, distance)   # virtual pin 2 for distancia
        #blynk.virtual_write(3, temp)   # virtual pin 3 for temp
        #blynk.virtual_write(4, agua)   # virtual pin 4 for agua

        # Run Blynk
        blynk.run()

def conecction_wifi()->None:
    # Configuración de la red Wi-Fi
    #SSID = 'INFINITUM6832_2.4'
    #PASSWORD = 'XnCjzCT8id'
    SSID = '#WUAMC'
    PASSWORD = 'wificua06'

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