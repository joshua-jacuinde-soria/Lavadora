map_cmd = {
    0x61: False,
    0x62: True,
    0x63: True,
    0x64: False,
    0x65: "Ciclo Lavado [0]",
    0x66: "Ciclo Lavado [1]",
    0x67: "Ciclo Lavado [2]",
    0x68: "Nivel de Agua [0]",
    0x69: "Nivel de Agua [1]",
    0x6A: "Nivel de Agua [2]",
    0x6B: "Tipo de Lavado [0]",
    0x6C: "Tipo de Lavado [1]",
    0x6D: "Tipo de Lavado [2]",
    0x6E: "Tipo de Lavado [3]",
    0x6F: "Tipo de Lavado [4]",
    0x70: "Tipo de Lavado [5]",
    0x71: "Tipo de Lavado [6]",
}

state_encendido: bool = False

state_pausa:bool = False

state_ciclo_lavado: str = ''

state_nivel_agua: str = ''

state_tipo_lavado: str = ''

nivel_leds = [0, 1, 2]