# **Implementación de DashBoard por medio del protocolo MQTT**

## **Introducción**
Este programa es una extensión del proyecto del Tablero de Lavadora para la UEA de Microcontroladores. 
La función de este programa es encargarse de leer los valores de los sensores que estén conectados al microcontrolador "Raspberry Pi Pico W" mediante el protocólo MQTT y se mostrarán en un Dashboard, todo esto implementado en el lenguaje "MicroPhyton".

## Funciones y herramientas principales

- `Mosquitto`: Eclipse Mosquitto es Broker MQTT un corredor de mensajes de código abierto (EPL/EDL) que implementa las versiones de protocolo MQTT 5.0, 3.1.1 y 3.1.
- `simple.py`: Es una biblioteca de Phyton que usaremos para poder hacer más simple la implementación del protocolo MQTT.
- `IoT MQTT Panel (Dashboard Móvil)`: Aplicación remota de Android para mostrar los valores enviados mediante el protocolo MQTT en tiempo real para visualizarlos de manera gráfica.
- `Blynk.console (Dashboard Web)`: Aplicación de Web para mostrar los valores enviados desde nuestro microocontrolador en tiempo real para visualizarlos de manera gráfica.
- `Main?`: Esta es nuestra la principal del programa, se encargará de ejecutar las funciones que leerán los valores que proporcionen los sensores del microocontrolador "Raspberry Pi Pico W", de conectarse a la red Wifi y de enviar los valores obtenidos al Broker Mosquitto.
- `Pruebas.py`: Es un documento en el cuál se están haciendo las pruebas necesarias para verificar el correcto funcionamiento del programa.
- `BlynkLib.py`: Es una biblioteca de Phyton que usaremos para poder conectar los datos que envie nuestro mictrocontrolador a la Web de Blynk.console.
- `MQTT_Final.py` : Programa final con los cambios implementados.

## Funcionamiento

#### Mosquitto

1. Primero tendremos que seguir el proceso de instalación de la herramienta Mosquitto para poder usarla sin problemas.
2. Nos ubicarememos en la carpeta que contiene el ejecutable de la aplicación por lo general en Windows se encuentra en la siguiente ruta: `"C:\Program Files\mosquitto"`.
3. Una vez aquí ya deberiamos tener configurado los archivos necesarios para poder evitar los porblemas de permisos.
4. Ejecutamos el siguiente comando en CMD para poder ejecutar Mosquitto (debemos estar ubicados dentro de la carpeta que contiene el ejecutable de Mosquitto): `"mosquitto -c mosquitto.conf"`.
5. Ahora que hemos habilidato el Broker Mosquitto, podemos hacer subscripciones y publicaciones directamente desde Mosquitto o cualquier aplicación que se conecte al IP que estamos trabajando; también es necesario conectarse al Puerto en el cúal estamos trabajando (este caso 1833).

Con el Broker habilitado solamente es cuestion de conectarnos al puerto 1833 por el IP en el que estemos trabajando, una vez hecho esto debemos configurar los dispositivos que queremos hacer subscripciones y publicaciones.

#### Funcionamiento del programa

El programa leera los valores que proporcionen los sensores que están conectados en la Raspberry Pi Pico W, enviando y publicando los mensajes al Broker Mosquitto al topico que se requiera. De aqui se conectará el dispositivo movil al Broker y leerá los datos publicados en el Broker, después de esto los mostrará de forma gráfica en la APP `IoT MQTT Panel (Dashboard Móvil)`. De la misma manera `Blynk.console (Dashboard Web)`, con la diferencia que la web no leerá los mensajes del Broker, sino que mediante la libreria ya implementadá leerá directamente los resultados envidados por las salidas directamente desde el programa sin necesidad de acceder al Broker.

#### Funciones

- `Pruebas.py`

- `read_and_publish()` : Con esta función nos encargmos de llamar a las funciones encargadas de leer los datos que nos proporcionaran los sensores conectados a la Raspberry Pi Pico W, posterior a esto mediante la lineas de código: `client.publish(MQTT_TOPIC_[Topico al cual publicamos], str([dato a publicar]))`, hacemos la publicación del valor obtenido.

- `conecction_wifi()` : Con esta función vamos a conectar la Raspberry Pi Pico W a la red que queramos usar para trabajar con la conexion WiFi.

## Conexiones.
- `No aplica` : Para código no se requieren conexiones adicionales, únicamente que el microocontrolador que estamos usando tenga conexión WiFi, de lo contrario no podra conectarse al Broker Mosquitto.