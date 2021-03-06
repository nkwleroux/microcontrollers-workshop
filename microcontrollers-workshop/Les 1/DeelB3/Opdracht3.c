/*
 * DeelB3.c
 *
 * Created: 03/2/2021 11:05:10 AM
 * Author : Nic & Jorn
 */ 

#define  F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>

void wait( int ms );

int main(void)
{
	DDRD = 0b11111111;	
	
    while (1) 
    {
		if (PINC & 0x01)
		{
			PORTD = 0x80;
			wait(100);
			PORTD = 0x00;
			wait(100);
		}
		else {
			PORTD = 0x00;
		}
    }
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

