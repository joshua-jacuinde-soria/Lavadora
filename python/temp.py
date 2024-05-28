from machine import Pin
from onewire import OneWire
from ds18x20 import DS18X20
import time

class TempSensor:
    def __init__(self, pin: int) -> None:
        self.pin = Pin(pin)
        self.ds_sensor: DS18X20 = DS18X20(OneWire(self.pin))
        self.roms = self.ds_sensor.scan()
        print("Found DS devices: ", self.roms)

    def get_temp(self) -> float:
        self.ds_sensor.convert_temp()
        return self.ds_sensor.read_temp(self.roms[0])
    
# test

test = TempSensor(15)
while True:
    print(test.get_temp())
    time.sleep(1)