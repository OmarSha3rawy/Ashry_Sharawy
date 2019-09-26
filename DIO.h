/*
 * DIO.h
 *
 * Created: 9/20/2019 3:42:23 PM
 *  Author: omar sha3rawy
 */ 


#ifndef DIO_H_
#define DIO_H_

#include <avr/io.h> // rewrite it
#include "DIO_configuration.h"
#include "std_types.h"

#define MAX_NUM_OF_PINS	(uint8)32

typedef enum{NOK,OK}func_state;


func_state DIO_init();
func_state DIO_read(pintype device, uint8* result);
//func_state DIO_read (uint8 port,uint8 pin,uint8 * Pval);
func_state DIO_write(pintype device, uint8 value);

#endif /* DIO_H_ */