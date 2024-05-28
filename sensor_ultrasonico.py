from machine import Pin
import time

trig = Pin(17, Pin.OUT)
echo = Pin(16, Pin.IN, Pin.PULL_DOWN)
def nivel():
     trig.value(0)
     time.sleep(0.1)
     trig.value(1)
     time.sleep_us(2)
     trig.value(0)
     while echo.value()==0:
          pulse_start = time.ticks_us()
     while echo.value()==1:
          pulse_end = time.ticks_us()
     pulse_duration = float(pulse_end) - float(pulse_start)
     distance = pulse_duration * 17165 / 1000000
     distance = round(distance, 0)
     
def main():
     nivel()