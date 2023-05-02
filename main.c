#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

void internalLed()
{
	DDRB |= (1 << 5);
	while (1)
	{
		BIT_SET(PORTB, 5);
		_delay_ms(1000);
		BIT_CLEAR(PORTB, 5);
		_delay_ms(500);
		printf("Hello\n");
	}

}


int main(void)
{
	internalLed();
	return 0;
}