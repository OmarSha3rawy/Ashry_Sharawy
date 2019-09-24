/*
 * _7segment.c
 *
 * Created: 9/21/2019 2:53:22 PM
 *  Author: omara
 */ 

#include "segment.h"

func_state SEG_Write(uint8 num)
{
	func_state state = OK; 
	switch(num)
	{
		case (uint8)0 : 
			DIO_write(seg0,(uint8)0);
			DIO_write(seg1,(uint8)0);
			DIO_write(seg2,(uint8)0);
			DIO_write(seg3,(uint8)0);
		break;
		
		case 1 :
			DIO_write(seg0,(uint8)1);
			DIO_write(seg1,(uint8)0);
			DIO_write(seg2,(uint8)0);
			DIO_write(seg3,(uint8)0);
		break;
		case 2 :
			DIO_write(seg0,(uint8)0);
			DIO_write(seg1,(uint8)1);
			DIO_write(seg2,(uint8)0);
			DIO_write(seg3,(uint8)0);
		break;
		case 3 :
			DIO_write(seg0,(uint8)1);
			DIO_write(seg1,(uint8)1);
			DIO_write(seg2,(uint8)0);
			DIO_write(seg3,(uint8)0);
		break;
		case 4 :
			DIO_write(seg0,(uint8)0);
			DIO_write(seg1,(uint8)0);
			DIO_write(seg2,(uint8)1);
			DIO_write(seg3,(uint8)0);
		break;
		case 5 :
			DIO_write(seg0,(uint8)1);
			DIO_write(seg1,(uint8)0);
			DIO_write(seg2,(uint8)1);
			DIO_write(seg3,(uint8)0);
		break;
		case 6 :
			DIO_write(seg0,(uint8)0);
			DIO_write(seg1,(uint8)1);
			DIO_write(seg2,(uint8)1);
			DIO_write(seg3,(uint8)0);
		break;
		case 7 :
			DIO_write(seg0,(uint8)1);
			DIO_write(seg1,(uint8)1);
			DIO_write(seg2,(uint8)1);
			DIO_write(seg3,(uint8)0);
		break;
		case 8 :
			DIO_write(seg0,(uint8)0);
			DIO_write(seg1,(uint8)0);
			DIO_write(seg2,(uint8)0);
			DIO_write(seg3,(uint8)1);
		break;
		case 9 :
			DIO_write(seg0,(uint8)1);
			DIO_write(seg1,(uint8)0);
			DIO_write(seg2,(uint8)0);
			DIO_write(seg3,(uint8)1);
		break;
		default:
			DIO_write(seg0,(uint8)0);
			DIO_write(seg1,(uint8)0);
			DIO_write(seg2,(uint8)0);
			DIO_write(seg3,(uint8)0);
			state = NOK;
		break;		
	}
	return state;
}