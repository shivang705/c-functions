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
 * @file <stats.h>
 * @brief <Header file for Data Statistics functions performed on a Data Set>
 *
 * <This file contains Function declarations used for Data Statistics>
 *
 * @author <Shivang Patel>
 * @date <7th April, 2020>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__ 

/*
 * @function <print_statistics>
 * 
 * @brief <Function to print Data Statistics such as Sorted Data Set in Descending Order, 
 *        Mean, Median, Maximum and Minimum of the Data Set.> 
 *        <'sort_array' function will be called using first two parameters. This will sort the data set in Descending Order> 
 *        <The sorted data set will be printed using 'print_array' function>
 *        <Mean value calculated from 'find_mean' function will be the third parameter and displayed using 'printf' function>
 *        <Median value calculated from 'find_median' function will be the fourth parameter and displayed using 'printf' function>
 *        <Minimum value calculated from 'find_minimum' function will be the fifth parameter and displayed using 'printf' function>
 *        <Maximum value calculated from 'find_maximum' function will be the sixth parameter and displayed using 'printf' function>
 */
void stats(void);
/*
 * @param <unsigned char *arr_ptr> <A 8-bit pointer assigned to the Data Set array. It will store the address of the first element of Data Set>
 * @param <unsigned char arr_len> <A 8-bit variable which will store the size of the data set>
 * @param <unsigned char mean> <A 8-bit variable which will store the mean value of the data set>
 * @param <unsigned char median> <A 8-bit variable which will store the median value of the data set>
 * @param <unsigned char minimum> <A 8-bit variable which will store the minimum value of the data set>
 * @param <unsigned char maximum> <A 8-bit variable which will store the maximum value of the data set>
 */
void print_statistics(unsigned char *arr_ptr, 
					  unsigned int arr_len, 
					  unsigned char mean, 
					  unsigned char median, 
					  unsigned char minimum, 
					  unsigned char maximum);

/**
 * @function <print_array>
 *
 * @brief <Function to print Data Set array>
 *		  <The first parameter will store the address of first element of Data Set array>
 *        <It will be printed using 'printf' function and the first parameter will be incremented>
 *		  <The process continuess untill the size of array is reached which is defined by second parameter>	
 *
 * @param <unsigned char *arr_ptr> <A 8-bit pointer assigned to the Data Set array. It will store the address of the first element of Data Set>
 * @param <unsigned char arr_len> <A 8-bit variable which will store the size of the data set>
 */
void print_array(unsigned char *arr_ptr, unsigned int arr_len);

/*
 * @function <find_mean>
 * 
 * @brief <Function to find the Mean value from the Data set>
 * 	      <Each element of the Data Set will be added together and will be divided by size of data set to get mean value> 
 * 		  <The mean value is returned> 
 *
 * @param <unsigned char *arr_ptr> <A 8-bit pointer assigned to the Data Set array. It will store the address of the first element of Data Set>
 * @param <unsigned char arr_len> <A 8-bit variable which will store the size of the data set>
 *
 * @return <This function will return 8 bit mean value>
 */
unsigned char find_mean(unsigned char *arr_ptr, unsigned int arr_len);

/*
 * @function <find_mean>
 * 
 * @brief <Function to find the Median value from the Data set>
 *        <Data set will first sorted by 'sort_array' function in descending order>
 * 	      <The centre element of the data set will get by dividing the Data set size into half> 
 * 		  <This will be the median value and is returned>
 * 
 * @param <unsigned char *arr_ptr> <A 8-bit pointer assigned to the Data Set array. It will store the address of the first element of Data Set>
 * @param <unsigned char arr_len> <A 8-bit variable which will store the size of the data set>
 *
 * @return <This function will return 8 bit median value>
 */
unsigned char find_median(unsigned char *arr_ptr, unsigned int arr_len);

/*
 * @function <find_maximum>
 * 
 * @brief <Function to find the Maximum value from the Data set>
 *        <Data set will first sorted by 'sort_array' function in descending order>
 * 	      <The first element of the data set will get by the pointer> 
 * 		  <This will be the maximum value and is returned>
 * 
 * @param <unsigned char *arr_ptr> <A 8-bit pointer assigned to the Data Set array. It will store the address of the first element of Data Set>
 * @param <unsigned char arr_len> <A 8-bit variable which will store the size of the data set>
 *
 * @return <This function will return 8 bit maximum value>
 */
unsigned char find_maximum(unsigned char *arr_ptr, unsigned int arr_len);

/*
 * @function <find_minimum>
 * 
 * @brief <Function to find the Minimum value from the Data set>
 *        <Data set will first sorted by 'sort_array' function in descending order>
 * 	      <The last element of the data set will get by the pointer and data set size> 
 * 		  <This will be the minimum value and is returned>
 * 
 * @param <unsigned char *arr_ptr> <A 8-bit pointer assigned to the Data Set array. It will store the address of the first element of Data Set>
 * @param <unsigned char arr_len> <A 8-bit variable which will store the size of the data set>
 *
 * @return <This function will return 8 bit minimum value>
 */
unsigned char find_minimum(unsigned char *arr_ptr, unsigned int arr_len);

/*
 * @function <sort_array>
 * 
 * @brief <Function to sort the Data Set array in descending order>
 *        <This function uses bubble sort algorithm to sort the data set array using time complexity of O(n^2)>
 * 	      <The adjacent elements of the Data Set is compared and swapped if not in order> 
 * 		  <This continues untill the whole Data Set is sorted>
 *        <The sorted data set is then returned>
 *
 * @param <unsigned char *arr_ptr> <A 8-bit pointer assigned to the Data Set array. It will store the address of the first element of Data Set>
 * @param <unsigned char arr_len> <A 8-bit variable which will store the size of the data set>
 *
 * @return <This function will return a 8-bit pointer assigned to the sorted Data set>
 */
unsigned char sort_array(unsigned char *arr_ptr, unsigned int arr_len);

#endif /* __STATS_H__ */
