/*
 * CAR_APP.c
 *
 * Created: 9/26/2019 10:13:48 AM
 * Author : omara
 */ 

#include <avr/io.h>
#include "segment.h"
#include "DIO.h"
#include "Timers.h"

#define F_CPU 1000000UL


int main(void)
{
	func_state ack;
	func_state ack2;

	uint8 time_counter = 0;
	
	DIO_init();	
	ack=TIMER_init();
	
    while (1) 
    {
		DIO_write(motor0, HIGH);
		DIO_write(motor1, LOW);	
		for (time_counter = 0; time_counter < 10; time_counter++)
		{
			ack = SEG_Write(time_counter);
			if(ack != OK)
			{
				DIO_write(led_flag, HIGH);
			}
			ack2=TIMER_delay_ms(timer0,1000);
		}
		
		DIO_write(motor0, LOW);
		DIO_write(motor1, HIGH);
		for (time_counter = 0; time_counter < 10; time_counter++)
		{
			ack = SEG_Write(time_counter);
			if(ack != OK)
			{
				DIO_write(led_flag, HIGH);
			}
			ack2=TIMER_delay_ms(timer0,1000);
		}
	}
	return 0;
}

