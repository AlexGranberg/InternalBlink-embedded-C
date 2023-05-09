#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "millis.h"

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 


int main(void)
{
	millis_init();
	unsigned long prev_millis;
	prev_millis = millis();
	sei();

	DDRB |= (1 << 5);
	while (1)
	{
		if (millis() - prev_millis > 500){
			PORTB ^= (1 << 5);
			prev_millis = millis();
		}
	}
	return 0;
}