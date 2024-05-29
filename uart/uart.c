#include "uart.h"

int main()
{
    inicio_uart();

    inicio_led_button();
    while (true)
    {
        if (!gpio_get(BUTTON_GPIO)) {
            gpio_put(LED, 1);
            // sends a command to the receiver
            uart_putc(UART_ID, cmd+0x30); // <-- add hex value of '0' to the command
            cmd = (cmd + 1) & 3; // <-- increment the command and wrap around
            sleep_ms(1000);
        }
        gpio_put(LED, 0);
    }
}