/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Source file for Data Statistics functions performed on a Data Set>
 *
 * <This file is used to do Data Statistics such as Mean, Median, Maximum, Minimum, Data Set Sorting>
 *
 * @author <Shivang Patel>
 * @date <7th April, 2020>
 *
 */

#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void stats(void) {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  unsigned char mean = 0;		//To store the mean value returned by 'find_mean' function
  unsigned char median = 0;		//To store the median value returned by 'find_median' function
  unsigned char maximum = 0;	//To store the maximum value returned by 'find_maximum' function
  unsigned char minimum = 0;	//To store the minimum value returned by 'find_minimum' function
 
  print_array(test,SIZE);
  mean = find_mean(test,SIZE);
  median = find_median(test,SIZE);
  maximum = find_maximum(test,SIZE);
  minimum = find_minimum(test,SIZE);
  print_statistics(test,SIZE,mean,median,minimum,maximum);
}
	
void print_statistics(unsigned char *arr_ptr, unsigned int arr_len, unsigned char mean, unsigned char median, unsigned char minimum, unsigned char maximum){
	
	PRINTF("Sorted ");
	print_array(arr_ptr, arr_len);
	PRINTF("Mean = %d\n", mean);
	PRINTF("Median = %d\n", median);
	PRINTF("Maximum = %d\n", maximum);
	PRINTF("Minimum = %d\n", minimum);
}

void print_array(unsigned char *arr_ptr, unsigned int arr_len){
	
	#ifdef VERBOSE
	PRINTF("Array = { ");	
	for(unsigned int i = 0; i < arr_len; i++)
        PRINTF("%d ", *(arr_ptr + i));
    PRINTF("}\n");
    #endif
}

unsigned char find_mean(unsigned char *arr_ptr, unsigned int arr_len){

	unsigned int mean = 0;
	for(unsigned int i = 0; i < arr_len; i++)
		mean += *(arr_ptr + i);
	mean = mean/arr_len;
	return mean;
}

unsigned char find_median(unsigned char *arr_ptr, unsigned int arr_len){

	unsigned char median = 0;
	*arr_ptr = 	sort_array(arr_ptr, arr_len);
	median = *(arr_ptr + (arr_len/2));
	return median;
}

unsigned char find_maximum(unsigned char *arr_ptr, unsigned int arr_len){

	unsigned char maximum = 0;
	*arr_ptr = 	sort_array(arr_ptr, arr_len);
	maximum = *arr_ptr;	
	return maximum;
}

unsigned char find_minimum(unsigned char *arr_ptr, unsigned int arr_len){

	unsigned char minimum = 0;
	*arr_ptr = 	sort_array(arr_ptr, arr_len);
	minimum = *(arr_ptr + (arr_len - 1));
	return minimum;
}

unsigned char sort_array(unsigned char *arr_ptr, unsigned int arr_len){

	for(unsigned int i = 0; i < arr_len; i++){
		for(unsigned int j = 0; j < i; j++){
			if(*(arr_ptr + j) < *(arr_ptr + i)){
				*(arr_ptr + j) = *(arr_ptr + j) + *(arr_ptr + i);
				*(arr_ptr + i) = *(arr_ptr + j) - *(arr_ptr + i);
				*(arr_ptr + j) = *(arr_ptr + j) - *(arr_ptr + i);
			}
		}
	}

	return *arr_ptr;
}