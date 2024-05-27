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
MQTT_TOPIC_DHT1 = 'sensors/temp'
MQTT_TOPIC_DHT2 = 'sensors/hum'
client = MQTTClient('Raspberrry_Pi_Pico_W', MQTT_SERVER, port=MQTT_PORT)

