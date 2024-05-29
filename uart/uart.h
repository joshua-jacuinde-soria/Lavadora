#ifndef UART_H
#define UART_H

#define UART_TX_PIN 0
#define UART_RX_PIN 1

#define UART_ID uart0
#define BAUD_RATE 9600
#define BUTTON_GPIO 15
#define LED 16

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/gpio.h"

uint8_t cmd;

void inicio_uart() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

void inicio_led_button() {
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    gpio_put(LED, 0);
}

void send_cmd(int state, int offset) {
    cmd  = 0;
    uart_putc(UART_ID, cmd + offset);
}


#endif