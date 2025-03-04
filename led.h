#pragma once

#include "avr/io.h"

void led_init(void);
void led_toggle(void);

inline void led_init(void) {
  DDRB |= (1 << PB5);
}

inline void led_toggle(void) {
  PORTB ^= (1 << PB5);
}
