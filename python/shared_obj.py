map_cmd = {
    0x61: False,
    0x62: True,
    0x63: True,
    0x64: False,
    0x65: "Fuzzy",
    0x66: "Rapido",
    0x67: "Pesado",
    0x68: "Bajo",
    0x69: "Medio",
    0x6A: "Alto",
    0x6B: "Lavar",
    0x6C: "Enjuagar",
    0x6D: "Centrifugar",
    0x6E: "Lavar - Enjuagar",
    0x6F: "Lavar - Centrifugar",
    0x70: "Enjuagar - Centrifugar",
    0x71: "Lavado Completo",
}

state_encendido: bool = False

state_pausa:bool = False

state_ciclo_lavado: str = ''

state_nivel_agua: str = ''

state_tipo_lavado: str = ''

nivel_leds = [0, 1, 2]