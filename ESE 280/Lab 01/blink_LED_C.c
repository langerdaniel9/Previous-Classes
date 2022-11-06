/*
 * blink_LED_C.c
 *
 * Created: 8/31/2022 10:32:57 AM
 * Author : Daniel Langer
 */ 

#define F_CPU 4000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    VPORTB.DIR |= PIN3_bm;
	
    while (1) // repeat the following instructions forever
    {
		VPORTB.OUT |= PIN3_bm;	// set PB3
		_delay_ms(500);			// delay 500ms
		VPORTB.OUT &= ~PIN3_bm;	// clear PB3
		_delay_ms(500);			// delay 500ms
    }
	
	return 0;
}

