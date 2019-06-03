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
 * @param mean Mean value of data items in the array
 * @param median Median value of data items in the array
 *
 */
void print_statistics(char min, char max, int mean, char median);

 /**
 * @brief Print array to terminal.
 *
 * This function takes a char pointer to an array as input.This will print elements in the array to terminal.
 *
 * @param *arrayPtr  Pointer to array
 * @param SIZE Size of array
 *
 */ 
void print_array(char *arrayPtr);

/**
 * @brief Find median value of data in array.
 * 
 * This function take a char pointer to an array as input and output a char which is median value of data in array.
 *
 * @param *arrayPtr  Pointer to array
 * @param SIZE Size of array
 *
 * return Char which is median value
 */
char find_median( char *arrayPtr, int SIZE);

/**
 * @brief Find mean value of data in array.
 * 
 * This function take a char pointer to an array as input and output an interger which is mean value of data in array.
 * 
 * @param *arrayPtr  Pointer to array
 * @param SIZE Size of array
 * 
 * return Interger which is mean value 
 */ 
int find_mean( char *arrayPtr, int SIZE);

/**
 * @brief Find maximun value of data in array.
 *  
 * This function take a char pointer to an array as input and output a char which is maximum value in array.
 *     
 * @param *arrayPtr  Pointer to array
 * @param SIZE Size of array
 *   
 * return Char which is maximum value 
 */
char find_maximum( char *arrayPtr, int SIZE);

/**
 *  @brief Find minimum value of data in array.
 *    
 *  This function take a char pointer to an array as input and output a char which is minimum value of in array.
 *      
 *  @param *arrayPtr  Pointer to array
 *  @param SIZE Size of array
 *       
 *  return Char which is minimum value 
 */
char find_minimum( char *arrayPtr, int SIZE);

/**
 *  @brief Sort element in array in descending order.
 *   
 *  This function take a char pointer to an array as input.This sort elements in array in descending order.
 *     
 *  @param *arrayPtr  Pointer to array
 *  @param SIZE Size of array
 *        
 */
void sort_array( char *arrayPtr, int SIZE)

#endif /* __STATS_H__ */
