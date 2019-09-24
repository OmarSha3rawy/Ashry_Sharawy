/*
 * timers_configuration.c
 *
 * Created: 9/21/2019 6:51:41 PM
 *  Author: omara
 */ 
#include "timers_configuration.h"
timer_confg timer_confg_list[num_of_timers]={
	{INITIALIZED,CTC,NA,(uint8)250, PRE_STOPPED, CLOCK_1MHZ,INTERRUPT_EN},
	//{INITIALIZED,CTC,NA,(uint8)250, PRE_STOPPED, CLOCK_1MHZ,INTERRUPT_EN},
	//{INITIALIZED,CTC,NA,(uint8)250, PRE_STOPPED, CLOCK_1MHZ,INTERRUPT_EN}
	};