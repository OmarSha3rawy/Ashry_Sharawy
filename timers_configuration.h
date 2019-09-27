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

/* #define NO_ACTION 0
#define TOGGLE 1
#define SET_ON 2
#define CLEAR_ON 3
#define INVERTING 4
#define NON_INVERTING 5 */

typedef enum{
	NO_ACTION = 0,
	TOGGLE = 1,
	CLEAR_ON = 2,
	SET_ON = 3,
	
	TOGGLE_OC1A = 1,
	NON_INVERTING = 2,
	INVERTING = 3,
	
	CLEAR_ON_UP = 2,
	SET_ON_UP = 3}timers_actions;

typedef enum{
	ON = 1,
	OFF = 0}Timer1_Noise;

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

typedef enum{
	NORMAL,
	PHASE_CORRECT_8,
	PHASE_CORRECT_9,
	PHASE_CORRECT_10,
	CTC_OC,
	FAST_PWM_8,
	FAST_PWM_9,
	FAST_PWM_10,
	PHASE_FREQ_CORRECT_ICR,
	PHASE_FREQ_CORRECT_OC,
	PHASE_CORRECT_ICR,
	PHASE_CORRECT_OC,
	CTC_ICR,
	FAST_PWM_ICR = 14,
	FAST_PWM_OC = 15,
	num_of_modes}timer1_modes;



typedef enum{timer0, timer1, timer2, num_of_timers}timer_id;
typedef struct
{
	uint8 state;
	uint8 mood;
	uint8 action1;
	uint8 action2;
	uint8 compare_value;
	uint16 compare_value16_A;
	uint16 compare_value16_B;
	uint8 prescale;
	uint8 clock;
	uint8 interrupt;
	}timer_confg;
	extern timer_confg timer_confg_list[num_of_timers];





#endif /* TIMERS_CONFIGURATION_H_ */