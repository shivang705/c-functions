/**
 * @file data.c
 * @brief Abstraction of data read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to data via function calls.
 *
 * @author Shivang Patel
 * @date April 30 2020
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "platform.h"

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base){

	uint8_t length = 0;
	*ptr = '\0';
	ptr++;
	length++;
	if (data == 0) { 
        *ptr = '0';
        ptr++; 
        length++;

        return length; 
    }
	uint32_t uint_data;
	if(base == 10 && data < 0){
		uint_data = data * -1;
	}
	else{
		uint_data = data;
	}
	while(uint_data != 0){
    	if((uint_data % base) > 9){
				*ptr = ((uint_data % base) - 10) + 'a';
    	}
		else{
				*ptr = (uint_data % base) + '0';
		}
		ptr++;
		length++;
		uint_data /= base;
	}
	if(data < 0 && base == 10){
		*ptr = '-';
		length++;    		
	}
	return length; 
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

	ptr = ptr + digits - 1;
	uint32_t uint_data = 0;
	uint8_t minus = 0;
	uint32_t power = 1;
	digits--;
	if(*ptr == '-'){
		minus = 1;
		ptr--;
		digits--;
	}
	for(uint8_t i = (digits - 1); i > 0; i--){
		power = 1;
		for(uint8_t j = 1; j <= i; j++){
			power *= base;
		}
		if(*ptr > 57){
			uint_data += (*ptr - 'a' + 10) * power;
		}
		else{
			uint_data += (*ptr - '0') * power;
		}
		ptr--;
	}
	if(*ptr > 57){
		uint_data += (*ptr - 'a' + 10);
	}
	else{
		uint_data += (*ptr - '0');
	}
	int32_t data = (int32_t)uint_data;
	if(base == 10 && minus == 1){
		data = data * -1;
	}
	return data;
}