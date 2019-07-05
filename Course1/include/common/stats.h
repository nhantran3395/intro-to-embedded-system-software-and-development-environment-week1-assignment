/**
 * @file <stats.h> 
 * @brief Contains decleration of functions used for printing, sorting and finding statistics of given array of unsigned char data items.
 *
 *This file contains delerations for following functions:
 *	print_statistics()
 *	print_array()
 *	find_median()
 *	find_mean()
 *	find_maximum()
 *	find_minimum()
 *	sort_array()
 *
 *
 * @author <Tran Thanh Nhan>
 * @date <03/06/2019>
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Print statistics of given char-type array. 
 *
 * This function takes min, max, mean, median as input and print these value to terminal. 
 *
 * @param min Minimum value from array
 * @param max Maximum value from array
 * @param mean Mean value of data items in array
 * @param median Median value of data items in the array
 *
 */
void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median);

 /**
 * @brief Print array to terminal.
 *
 * This function takes a char pointer to an array as input.This will print elements in the array to terminal.
 *
 * @param *arrayPtr  Pointer to array
 * @param arraySize Size of array
 *
 */

void print_array(unsigned char *arrayPtr, int arraySize);

/**
 * @brief Find median value of data in array.
 * 
 * This function take a char pointer to an array as input and output a char which is median value of data in array.
 *
 * @param *arrayPtr  Pointer to array
 * @param arraySize Size of array
 *
 * return Char which is median value
 */
unsigned char find_median( unsigned char *arrayPtr, int arraySize);

/**
 * @brief Find median value of data in array.
 * 
 * This function take a char pointer to an array as input and output an interger which is mean value of data in array.
 * 
 * @param *arrayPtr  Pointer to array
 * @param arraySize Size of array
 * 
 * return Char which is mean value 
 */ 
unsigned char  find_mean( unsigned char *arrayPtr, int arraySize);

/**
 * @brief Find maximun value of data in array.
 *  
 * This function take a char pointer to an array as input and output a char which is maximum value in array.
 *     
 * @param *arrayPtr  Pointer to array
 * @param arraySize Size of array
 *   
 * return Char which is maximum value 
 */
unsigned char  find_maximum( unsigned char *arrayPtr, int arraySize);

/**
 *  @brief Find minimum value of data in array.
 *    
 *  This function take a char pointer to an array as input and output a char which is minimum value of in array.
 *      
 *  @param *arrayPtr  Pointer to array
 *  @param arraySize Size of array
 *       
 *  return Char which is minimum value 
 */
unsigned char find_minimum(unsigned  char *arrayPtr, int arraySize);

/**
 *  @brief Sort element in array in descending order.
 *   
 *  This function take a char pointer to an array as input.This sort elements in array in descending order.
 *     
 *  @param *arrayPtr  Pointer to array
 *  @param arraySize Size of array
 *        
 */
void sort_array( unsigned char *arrayPtr, int arraySize);

#endif /* __STATS_H__ */
