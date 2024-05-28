from machine import Pin
from time import sleep, sleep_us, ticks_us

trig = Pin(17, Pin.OUT)
echo = Pin(16, Pin.IN, Pin.PULL_DOWN)
def nivel():
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
     return level
     
def main():
     while True:
          level = nivel()
          if level == 0:
               mensaje = 'alerta muy lleno'
          elif level == 1:
               mensaje = 'alto'
          elif level == 2:
               mensaje = 'medio'
          elif level == 3:
               mensaje = 'bajo'
          else:
               mensaje = 'minimo'
          print('Nivel de agua: ', mensaje)
          sleep(1)