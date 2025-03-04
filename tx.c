#define F_CPU 16000000UL
#define BAUD 9600UL

#include "util/delay.h"
#include "uart.h"

int next_fib(void);

int main(void) {
  uart_init();
  
  while (1) {
    uart_tx(next_fib());
    _delay_ms(2000);
  }

  return 0;
}

#define MAX_ITER 20

int next_fib(void) {
  static int iter = 0;
  static int f_0 = 0;
  static int f_1 = 1;

  if (iter >= MAX_ITER) {
    iter = 0;
    f_0 = 0;
    f_1 = 1;
  }

  int f_2 = f_0 + f_1;

  f_0 = f_1;
  f_1 = f_2;
  
  iter++;

  return f_2;
}
