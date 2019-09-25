/*
 * timers.h
 *
 * Created: 9/21/2019 6:50:42 PM
 *  Author: omara
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_
/*#define OK  1
#define NOK 0*/

#include "timers_configuration.h"
#include "DIO.h"

#define MAX_NUM_OF_TIMERS (uint8)3

uint8 TIMER_init(void);
uint8 TIMER_delay_ms(timer_id id, uint8 val);
uint8 TIMER_pwm(timer_id id, uint8 duty);
uint8 TIMER_set(timer_id id, uint8 val);


#endif /* TIMERS_H_ */