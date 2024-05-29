# UART Micropython

El proposito de este documento es el de documentar las conexiones utilizadas que fueron necesarias para lograr recibir los comandos del microcontrolador "master" 

# Cogigo que recibe comandos

El codigo funciona de tal manera que cada vez que se el "master" envia algun comando, como se activa el puerto UART el "slave" entraria a ver que se ha escrito en el puerto y actualizara el estado de acuerdo al comando que se ha mandado

``` python
if uart.any():
    # Lectura comando
    cmd = uart.read(1)
    # Uso de try except por errores inesperados
    try:
        ...
    except:
        ...
    else:
        # Al leer con exito el comando se aplica la logica correspondiente para actualizar los estados
        ...
```

# Conexiones

## Puerto UART
|   "Master"	|   "Slave"	|
|---	|---	|
|   GPIO-0    |     GPIO-1 	   |
|   GPIO-1    |     GPIO-0     |