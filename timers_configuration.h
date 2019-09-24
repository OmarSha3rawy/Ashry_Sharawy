/*
 * timers_configuration.h
 *
 * Created: 9/21/2019 6:52:19 PM
 *  Author: omara
 */ 


#ifndef TIMERS_CONFIGURATION_H_
#define TIMERS_CONFIGURATION_H_

#include "std_types.h"
#include <avr/io.h>

#define INITIALIZED 1
#define NOT_INITIALIZED 0

#define NA 0xff

#define NORMAL_MOOD 0
#define CTC 1
#define FAST_PWM 2
#define PHASE_CORRECT 3

#define NO_ACTION 0
#define TOGGLE 1
#define SET_ON 2
#define CLEAR_ON 3
#define INVERTING 4
#define NON_INVERTING 5


#define CLOCK_1MHZ 0
#define CLOCK_8MHZ 0

#define PRE_STOPPED 0 
#define PRE_1 1
#define PRE_8 2
#define PRE_64 3
#define PRE_256 4
#define PRE_1024 5
#define EXTERN_RISING 6
#define EXTERN_FALLING 7

#define INTERRUPT_EN 1
#define INTERRUPT_DIS 0

typedef enum{timer0,timer1,timer2,num_of_timers}timer_id;
typedef struct
{
	uint8 state;
	uint8 mood;
	uint8 action;
	uint8 compare_value;
	uint8 prescale;
	uint8 clock;
	uint8 interrupt;
	}timer_confg;
	extern timer_confg timer_confg_list[num_of_timers];





#endif /* TIMERS_CONFIGURATION_H_ */