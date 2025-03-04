#define F_CPU 16000000UL
#define BAUD 9600UL

#include "util/delay.h"
#include "uart.h"
#include "led.h"

int main(void) {
  uart_init();
  led_init();

  while (1) {
    int next_fib = uart_rx();

    for (int i = 0; i < next_fib; i++) {
      led_toggle();
      _delay_ms(50);
    }
    _delay_ms(2000);
  }

  return 0;
}
