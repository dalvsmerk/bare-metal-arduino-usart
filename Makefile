-include .env

MCU 	 = atmega328p
F_CPU  = 16000000UL

CC 		 = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

all: tx.hex rx.hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

tx.elf: tx.o
	$(CC) $(CFLAGS) -o $@ tx.o

rx.elf: rx.o
	$(CC) $(CFLAGS) -o $@ rx.o

tx.hex: tx.elf
	avr-objcopy -O ihex -R .eeprom $< $@

rx.hex: rx.elf
	avr-objcopy -O ihex -R .eeprom $< $@

flash-tx: tx.hex
	avrdude -c arduino -p $(MCU) -P $(PORT_TX) -b 115200 -U flash:w:tx.hex:i

flash-rx: rx.hex
	avrdude -c arduino -p $(MCU) -P $(PORT_RX) -b 115200 -U flash:w:rx.hex:i

clean:
	rm -f *.o *.elf *.hex

ls-dev:
	ls /dev/tty.usb*
