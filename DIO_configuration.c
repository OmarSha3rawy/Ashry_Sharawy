/*
 * DIO_configuration.c
 *
 * Created: 9/20/2019 3:42:04 PM
 *  Author: omara
 */ 

#include "DIO_configuration.h"

DIO_cnfig DIO_cnfig_list [NUM_OF_PINS] =
{
	//{PORT_B,PIN1,INPUT,NA,PULLUP,INITIALIZED},
	{PORT_D,PIN0,OUTPUT,LOW,NA,INITIALIZED},
	{PORT_D,PIN1,OUTPUT,LOW,NA,INITIALIZED},
		
	{PORT_C,PIN0,OUTPUT,LOW,NA,INITIALIZED},
	{PORT_C,PIN1,OUTPUT,LOW,NA,INITIALIZED},
	{PORT_C,PIN2,OUTPUT,LOW,NA,INITIALIZED},
	{PORT_C,PIN3,OUTPUT,LOW,NA,INITIALIZED},
		
	{PORT_B,PIN0,OUTPUT,LOW,NA,INITIALIZED}

};
