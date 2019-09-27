/*
 * timers.h
 *
 * Created: 9/21/2019 6:50:42 PM
 * Author: Ashry & sharawy
 * content: the timer driver APIs
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_
/*#define OK  1
#define NOK 0*/

#include "timers_configuration.h"
#include "DIO.h"

#define MAX_NUM_OF_TIMERS (uint8)3

/*
 * Function:  TIMER_init
 * --------------------
 * init the timers according to the configuration structure:
 *
 *  returns: error flag in case of unacceptaple configuration
 */
uint8 TIMER_init(void);


/*
 * Function:  TIMER_delay_ms
 * --------------------
 * delay for a specified period of time:
 *
 *  id: the ID of the timer in the configration array of structures
 *  val: the number of melliseconds to be delayed
 *
 *  returns: error flag in case of wrong input
 */
uint8 TIMER_delay_ms(timer_id id, uint32 val);

/*
 * Function:  TIMER_pwm
 * --------------------
 * generates a PWM signal with a specified duty cycles:
 *
 *  id: the ID of the timer in the configration array of structures
 *  duty: the duty cycle of the generated signal
 *
 *  returns: error flag in case of wrong input
 */
=======
uint8 TIMER_delay_ms(timer_id id, uint32 val);
uint8 TIMER_pwm(timer_id id, uint8 duty);



#endif /* TIMERS_H_ */