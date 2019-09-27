/*
 * _7segment.h
 *
 * Created: 9/21/2019 2:54:02 PM
 *  Author: omar sha3rawy
* content: the DIO driver APIs
 */ 


#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <avr/io.h>
#include "DIO.h"
#include "DIO_configuration.h"

/*
 * Function:  SEG_Write
 * --------------------
 * write a BCD number on the seven segment:
 *
 *  num: the value to shown on the seven segment
 *
 *  returns: error flag in case of wrong input
 */
func_state SEG_Write(uint8 num);





#endif /* SEGMENT_H_ */