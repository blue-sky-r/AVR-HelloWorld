/*
 */

#include <avr/io.h>
#include <util/delay.h>

// CONFIG section

// LED connection
#define LED         PORTB0
// UART baud speed
#define BD          9600
// LED blink frequency
#define LED_FREQ    1

// END of COBFIG section

/*
 To find Bus/Device use lsusb:
 > lsusb
 Bus 003 Device 005: ID 16c0:05dc Van Ooijen Technische Informatica shared ID for use with libusb

 Check permissions:
 > ls -l /dev/bus/usb/003/005
 crw-rw-r-- 1 root root 189, 260 apr 21 12:02 /dev/bus/usb/003/005

 Create 9-USBasp.rules
 > sudo joe /lib/udev/rules.d/99-USBasp.rules
 # USBasp - USB programmer for Atmel AVR controllers
 # Copy this file to /lib/udev/rules.d/

 SUBSYSTEM=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05dc", GROUP="dialout"

 Reconnect USB-ASP

 Check permissions:
 > ls -l /dev/bus/usb/003/005
 crw-rw-r-- 1 root dialout 189, 260 apr 21 12:02 /dev/bus/usb/003/005

 Verify avrdude is working:
 > avrdude -v -p m328p -P usb -c usbasp-clone -U flash:w:Blink.hex -U lfuse:w:Blink.lfs

 Code::Blocks Tools/configure/new
 Name: Flash
 Executable: avrdude
 Parameters: -p m328p -P usb -c usbasp-clone -U flash:w:${TARGET_OUTPUT_BASENAME}.hex
 Working directory: ${PROJECT_DIR}/${TARGET_OUTPUT_DIR}

*/

// baud rate to uart clock register
#define UBRR        F_CPU / BD / 16 - 1
// led frequency to delay in [ms]
#define SLEEP       LED_FREQ * 1000 / 2

int main(void)
{
    // PORTB0 LED output
    DDRB  |= (1 << LED);
    // LED ON
    PORTB |= (1 << LED);
    // UART Baud rate
    UBRR0L = UBRR;
    // UART format 8N1
    UCSR0C = (3 << UCSZ00);
    // UART enable TX
    UCSR0B = (1 << TXEN0);
    // loop forever
    while (1)
    {
        // wait
        _delay_ms(SLEEP);
        // toggle LED
        PORTB ^= (1 << LED);
        // Tx char U
        UDR0 = 'U';
    }
}
