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

def read_2():
    # Aqui va todo lo relacionado al sensor 2

def read_3():
    # Aqui va todo lo relacionado al sensor 3