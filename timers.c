/*
 * timers.c
 *
 * Created: 9/21/2019 6:51:17 PM
 *  Author: omara
 */ 

#include "timers.h"
#include <util/delay.h>
#include <avr/interrupt.h>
 uint8 Set_mode( uint8 id, uint8 mode);
 uint8  set_pre( uint8 id, uint8 pre);
uint8 set_action(uint8 id, uint8 action1, uint8 action2 );
 uint8 set_clock(uint8 id);
 uint8 set_interrupt(uint8 id, uint8 intr);
 uint8 set_ocr(uint8 id,uint8 val);
  uint8 volatile counter_0;
 uint8 volatile counter_2;
 

uint8 TIMER_init(void)
{
	uint8 state=OK;
	uint8 loop_index=0;
	if(num_of_timers<MAX_NUM_OF_TIMERS)
	{
		for(loop_index=0;loop_index<num_of_timers;loop_index++)
		{

			state=Set_mode(loop_index, timer_confg_list[loop_index].mood);
			if (state==NOK)
				timer_confg_list[loop_index].state=NOT_INITIALIZED;
			
			state=set_pre(loop_index,timer_confg_list[loop_index].prescale);
				if (state==NOK)
				timer_confg_list[loop_index].state=NOT_INITIALIZED;
				
			state=set_action(loop_index,timer_confg_list[loop_index].action1, timer_confg_list[loop_index].action2);	
			if (state==NOK)
				timer_confg_list[loop_index].state=NOT_INITIALIZED;
			
			state=set_clock(loop_index);
			if (state==NOK)
				timer_confg_list[loop_index].state=NOT_INITIALIZED;
			
			state=set_interrupt(loop_index,timer_confg_list[loop_index].interrupt);
			if (state==NOK)
				timer_confg_list[loop_index].state=NOT_INITIALIZED;
			
			state=set_ocr(loop_index,timer_confg_list[loop_index].compare_value);
			if (state==NOK)
				timer_confg_list[loop_index].state=NOT_INITIALIZED;
	}
	
}
else {
	state=NOK;
}
return state;
}

 uint8 Set_mode( uint8 id, uint8 mode)
{
	uint8 stat=OK;
	switch(id)
	{
		case timer0 : 
			if(mode == CTC)
			{
				TCCR0 &= ~(1<<WGM00);
				TCCR0 |= (1<<WGM01);
			}
			else if (mode == FAST_PWM)
			{
				TCCR0 |= (1<<WGM00);
				TCCR0 |= (1<<WGM01);				
			}
			else if (mode == PHASE_CORRECT)
			{
				TCCR0 |= (1<<WGM00);
				TCCR0 &= ~(1<<WGM01);				
			}
			else if(mode==NORMAL_MOOD)//norml mode
			{
				TCCR0 &= ~(1<<WGM00);
				TCCR0 &= ~(1<<WGM01);
				
			}
			else{
				stat=NOK;
			}
		break;
		
		case timer1:
			if(mode < 16)
			{
				TCCR1A |= (mode & 0x03);
				TCCR1B |= ((mode << 1) & 0x18);
				if (mode == NORMAL || mode == CTC_OC || mode == CTC_ICR)
				{
					TCCR1A |= ((1<<FOC1A) | (1<<FOC1B));
				}
				else
				{
					TCCR1A &= ~((1<<FOC1A) | (1<<FOC1B));
				}
			}
			else
			{
				stat=NOK;
			}
		break;
		
		case timer2:
			if(mode == CTC)
			{
				TCCR2 &= ~(1<<WGM20);
				TCCR2 |= (1<<WGM21);
			}
			else if (mode == FAST_PWM)
			{
				TCCR2 |= (1<<WGM20);
				TCCR2 |= (1<<WGM21);
			}
			else if (mode == PHASE_CORRECT)
			{
				TCCR2 |= (1<<WGM20);
				TCCR2 &= ~(1<<WGM21);
			}
			else if(mode==NORMAL_MOOD) //norml mode
			{
				TCCR2 &= ~(1<<WGM20);
				TCCR2 &= ~(1<<WGM01);
			}
			else{
				stat=NOK;
			}
		break;
		default:
		stat=NOK;
		break;
	}
	return stat;
}


 uint8  set_pre( uint8 id, uint8 pre){
	uint8 stat=OK;
	if(id==timer0){
		switch(pre){
		case PRE_STOPPED:
		TCCR0&=~(1<<CS00);
		TCCR0&=~(1<<CS01);
		TCCR0&=~(1<<CS02);
		break;
		case PRE_1:
		TCCR0|=(1<<CS00);
		TCCR0&=~(1<<CS01);
		TCCR0&=~(1<<CS02);
		break;
		case PRE_8:
		TCCR0&=~(1<<CS00);
		TCCR0|=(1<<CS01);
		TCCR0&=~(1<<CS02);
		break;
		case PRE_64:
		TCCR0|=(1<<CS00);
		TCCR0|=(1<<CS01);
		TCCR0&=~(1<<CS02);
		break;
		case PRE_256:
		TCCR0&=~(1<<CS00);
		TCCR0&=~(1<<CS01);
		TCCR0|=(1<<CS02);
		break;
		case PRE_1024:
		TCCR0|=(1<<CS00);
		TCCR0&=~(1<<CS01);
		TCCR0|=(1<<CS02);
		break;
		case EXTERN_RISING:
		TCCR0&=~(1<<CS00);
		TCCR0|=(1<<CS01);
		TCCR0|=(1<<CS02);
		break;
		case  EXTERN_FALLING:
		TCCR0|=(1<<CS00);
		TCCR0|=(1<<CS01);
		TCCR0|=(1<<CS02);
		break;
		default:
		stat=NOK;
		break;
		}
	}
	else if(id==timer1){
		if ( (pre >= 0) & (pre < 8)) //bad coding (replace in the first of function)
		{
			TCCR1B |= (pre & 0x07) ;
		}
		else
		{
			stat=NOK;		
		}
	}
	else if(id==timer2){
		switch(pre){
			case PRE_STOPPED:
			TCCR2&=~(1<<CS20);
			TCCR2&=~(1<<CS21);
			TCCR2&=~(1<<CS22);
			break;
			case PRE_1:
			TCCR2|=(1<<CS20);
			TCCR2&=~(1<<CS21);
			TCCR2&=~(1<<CS22);
			break;
			case PRE_8:
			TCCR2&=~(1<<CS20);
			TCCR2|=(1<<CS21);
			TCCR2&=~(1<<CS22);
			break;
			case PRE_64:
			TCCR2|=(1<<CS20);
			TCCR2|=(1<<CS21);
			TCCR2&=~(1<<CS22);
			break;
			case PRE_256:
			TCCR2&=~(1<<CS20);
			TCCR2&=~(1<<CS21);
			TCCR2|=(1<<CS22);
			break;
			case PRE_1024:
			TCCR2|=(1<<CS20);
			TCCR2&=~(1<<CS21);
			TCCR2|=(1<<CS22);
			break;
			case EXTERN_RISING:
			TCCR2&=~(1<<CS20);
			TCCR2|=(1<<CS21);
			TCCR2|=(1<<CS22);
			break;
			case  EXTERN_FALLING:
			TCCR2|=(1<<CS20);
			TCCR2|=(1<<CS21);
			TCCR2|=(1<<CS22);
			break;
			default:
			stat=NOK;
			break;
		}
	}
	else{
		stat=NOK;
	}
	return stat;
}

 uint8 set_action(uint8 id, uint8 action1, uint8 action2 ){
	uint8 stat=OK;
	if(id==timer0){
		if((timer_confg_list[id].mood==CTC)||(timer_confg_list[id].mood==NORMAL_MOOD)){
			switch(action1){
				case NO_ACTION:
				TCCR0&=~(1<<COM00);
				TCCR0&=~(1<<COM01);
				break;
				case TOGGLE:
				TCCR0|=(1<<COM00);
				TCCR0&=~(1<<COM01);
				break;
				case CLEAR_ON:
				TCCR0&=~(1<<COM00);
				TCCR0|=(1<<COM01);
				break;
				case SET_ON:
				TCCR0|=(1<<COM00);
				TCCR0|=(1<<COM01);
				break;
				default:
				stat=NOK;
				break;
			}
		}
		else if((timer_confg_list[id].mood==FAST_PWM)||(timer_confg_list[id].mood==PHASE_CORRECT)){
               
			   switch(action1){
				   
				 case INVERTING:
				 TCCR0|=(1<<COM00);
				 TCCR0|=(1<<COM01);
				 break;
				 case NON_INVERTING:
				 TCCR0&=~(1<<COM00);
				 TCCR0|=(1<<COM01);
				 break;
				 	default:
				 	stat=NOK;
				 	break;
					 }
		}
		else{
			stat=NOK;
			
		}
	}
	else if(id==timer1){
		if (( (action1 >= 0) & (action1 < 4)) & ((action2 >= 0) & (action2 < 4)))
		{
			TCCR1A |= (action1 << COM1A0);
			TCCR1A |= (action2 << COM1B0);
		}
		else
		{
			stat=NOK;	
		}	
	}
	else if(id==timer2){
		if((timer_confg_list[id].mood==CTC)||(timer_confg_list[id].mood==NORMAL_MOOD)){
			switch(action1){
				case NO_ACTION:
				TCCR2&=~(1<<COM20);
				TCCR2&=~(1<<COM21);
				break;
				case TOGGLE:
				TCCR2|=(1<<COM20);
				TCCR2&=~(1<<COM21);
				break;
				case CLEAR_ON:
				TCCR2&=~(1<<COM20);
				TCCR2|=(1<<COM21);
				break;
				case SET_ON:
				TCCR2|=(1<<COM20);
				TCCR2|=(1<<COM21);
				break;
				default:
				stat=NOK;
				break;
			}
		}
		else if((timer_confg_list[id].mood==FAST_PWM)||(timer_confg_list[id].mood==PHASE_CORRECT)){
			
			switch(action1){
				
				case INVERTING:
				TCCR2|=(1<<COM20);
				TCCR2|=(1<<COM21);
				break;
				case NON_INVERTING:
				TCCR2&=~(1<<COM20);
				TCCR2|=(1<<COM21);
				break;
				default:
				stat=NOK;
				break;
			}
		}
		else{
			stat=NOK;
			
		}
		
	}
	else{
		stat=NOK;
	}
	return stat;
}
 
 uint8 set_clock(uint8 id){
	uint8 stat;
	if((timer_confg_list[id].clock==CLOCK_1MHZ)||(timer_confg_list[id].clock==CLOCK_8MHZ)){
		stat=OK;
	}
	else
	{
		stat=NOK;
	}
	return stat;
}

 uint8 set_interrupt(uint8 id, uint8 intr){
	uint8 stat=OK;
	switch(id){
		case timer0:
		if(intr==INTERRUPT_EN){
			sei();
	if (timer_confg_list[id].mood==NORMAL_MOOD)
	{ TIMSK|=(1<<TOIE0);
		TIMSK&=~(1<<OCIE0);
	}
	else if ((timer_confg_list[id].mood==CTC)||(timer_confg_list[id].mood==FAST_PWM)||(timer_confg_list[id].mood==PHASE_CORRECT))
	{ TIMSK|=(1<<TOIE0);
		TIMSK|=(1<<OCIE0);
	}
	else{
		stat=NOK;
	}
	break;
	case timer1: // fe bug 3arsa hna | OCA AND OCB ACTIVATED 3AFYA | ICU NOT HANDLED 
		switch(timer_confg_list[id].mood)
		{
			case NORMAL: 
				TIMSK |= (1<<TOIE1);
			break;
			case CTC_OC:
				TIMSK |= (1<<OCIE1A);
				TIMSK |= (1<<OCIE1B);
			break;
			default: 
				TIMSK |= (1<<TOIE1);
			break;
		}
	break;
	case timer2:
	if (timer_confg_list[id].mood==NORMAL_MOOD)
	{ TIMSK|=(1<<TOIE2);
		TIMSK&=~(1<<OCIE2);
	}
	else if ((timer_confg_list[id].mood==CTC)||(timer_confg_list[id].mood==FAST_PWM)||(timer_confg_list[id].mood==PHASE_CORRECT))
	{ TIMSK|=(1<<TOIE2);
		TIMSK|=(1<<OCIE2);
	}
	else{
		stat=NOK;
	}
	break;
}
	}
return stat;
}

 uint8 set_ocr(uint8 id,uint8 val){
	uint8 stat=OK;
	switch(id){
	case timer0:
	if(val<255){
		OCR0=val;
	}
	else{
		stat=NOK;
		
	}
	break;
	case timer1:
		OCR1A = timer_confg_list[id].compare_value16_A ;
		OCR1B = timer_confg_list[id].compare_value16_B ;

	break;
	case timer2:
	if(val<255){
		OCR2=val;
	}
	else{
		stat=NOK;
		
	}
	break;
	default:
	stat=NOK;
	break;
	
	
	}
	return stat;
}

uint8 TIMER_delay_ms(timer_id id, uint8 val){
	  uint8 stat=OK;
	
	 switch(id){

	case timer0:
	stat=Set_mode(id,NORMAL_MOOD);
	stat=set_interrupt(id,INTERRUPT_EN);
	if(timer_confg_list[id].clock==CLOCK_1MHZ){
	stat=set_pre(id,PRE_1);
	TCNT0=6;
	}
	else if(timer_confg_list[id].clock==CLOCK_8MHZ){
		stat=set_pre(id,PRE_8);
		TCNT0=6;
	}
	 while(counter_0!=val*4);
	 counter_0=0;
	break;
	
	case timer2:
	stat=Set_mode(id,NORMAL_MOOD);
	stat=set_interrupt(id,INTERRUPT_EN);
	if(timer_confg_list[id].clock==CLOCK_1MHZ){
		stat=set_pre(id,PRE_1);
		TCNT2=6;
	}
	else if(timer_confg_list[id].clock==CLOCK_8MHZ){
		stat=set_pre(id,PRE_8);
		TCNT2=6;
	}
	   while(counter_2!=val*4)
	   counter_2=0;
     break;
	 }
	 
	 return stat;
}


uint8 TIMER_pwm(timer_id id, uint8 duty)
{
	uint8 stat=OK;
	uint16 val=0;
	if((duty>=0)&&(duty<=100)){
	switch(duty){
	case timer0:
	stat=Set_mode(id,FAST_PWM);
	stat=set_action(id,NON_INVERTING,NON_INVERTING);
	val=(duty*255)/100;
	OCR0=val;
	break;
	case timer1:
	stat=Set_mode(id,FAST_PWM_OC);
	stat=set_action(id,NON_INVERTING,NON_INVERTING);
	val=(duty*65536)/100;
	OCR1A=val;
	break;
	
	case timer2:
	stat=Set_mode(id,FAST_PWM);
	stat=set_action(id,NON_INVERTING,NON_INVERTING);
	val=(duty*255)/100;
	OCR2=val;

	break;
	}
	}
	else{
		stat=NOK;
	}
return stat;
	
	}
	void Start_Timer(uint8 id){
		uint8 stat=OK;
		switch(id){
			case timer0:
			stat=set_interrupt(id,INTERRUPT_EN);
			TCNT0=0;
			case timer1:
				stat=set_interrupt(id,INTERRUPT_EN);
				TCNT1=0;
			case timer2:
			stat=set_interrupt(id,INTERRUPT_EN);
			TCNT2=0;
			break;	
		}
	}
	void Stop_timer(uint8 id){
			uint8 stat=OK;
			switch(id){
				case timer0:
				stat=set_interrupt(id,INTERRUPT_DIS);
				TCNT0=0;
				case timer1:
				stat=set_interrupt(id,INTERRUPT_DIS);
				TCNT1=0;
				case timer2:
				stat=set_interrupt(id,INTERRUPT_DIS);
				TCNT2=0;
				break;
			}
		
		
	}

ISR(TIMER0_OVF_vect){
	counter_0++;
}
ISR(TIMER2_OVF_vect){
counter_2++;
	
}

