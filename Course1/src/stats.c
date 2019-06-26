/**
 * @file stats.c
 * @brief Analytic of array of char data items
 *
 * This program find minimum, maximum, mean, median value of a given array of unsigned char data items; and sort elements in this array in descending order. 
 *
 * @author <Tran Thanh Nhan>
 * @date <03/06/2019>
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include "stats.h"


/* Size of the Data Set */
#define SIZE (40)

void main() {

	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

	unsigned char mean=0,median=0,max=0,min=0;
	
	printf("Original array: \n");
	print_array(test,SIZE);
	
	printf("\n Array after being sorted in descending order: \n");
	sort_array(test,SIZE);
	print_array(test,SIZE);

	printf("\n Statistic of array can be calulated as follow: \n");
	mean = find_mean(test,SIZE);
	median = find_median(test,SIZE);
	max = find_maximum(test,SIZE);
	min = find_minimum(test,SIZE);
	print_statistics(min,max,mean,median);
}

void print_array ( unsigned char *arrayPtr, int arraySize){
	unsigned char *arrayPtrEnd = arrayPtr + arraySize;
	for (;arrayPtr<arrayPtrEnd;++arrayPtr)
	{
		printf("%d ",*arrayPtr);
	}
	printf("\n");
}

unsigned char find_mean ( unsigned char *arrayPtr, int arraySize){
	unsigned char *arrayPtrEnd = arrayPtr + arraySize;
	int sum = 0;
	float mean = 0;
       	for (;arrayPtr<arrayPtrEnd;++arrayPtr)	
	{
		sum += *arrayPtr;
	}
	mean = sum/arraySize;
	return mean;
}

unsigned char find_median ( unsigned char *arrayPtr, int arraySize){
	int parityCheck = (int)arraySize % 2; // 0:arraySize is even, 1:arraySize is odd
	unsigned char median;
	if (parityCheck == 1){
		median = *(arrayPtr + (arraySize)/2);
	}
	else 
	{
		int sum = *(arrayPtr + (arraySize)/2- 1) + *(arrayPtr + (arraySize)/2);
		median = sum/2;

	}		
	return median;
}

unsigned char find_maximum ( unsigned char *arrayPtr, int arraySize){
	unsigned char max  = *arrayPtr;
	for (int count = 0; count < arraySize-1; count++){
		if(max < *(arrayPtr+count+1)){
			max = *(arrayPtr+count+1);
		}
	       			
	}
	return max;
}

unsigned char find_minimum ( unsigned char *arrayPtr, int arraySize){
	unsigned char min  = *arrayPtr;
	for (int count = 0; count < arraySize-1; count++){
		if(min > *(arrayPtr-1)){
			    min = *(arrayPtr + count+1) ;
		}
	}
	return min;
}

void sort_array ( unsigned char *arrayPtr, int arraySize)
{
	unsigned char temp = 0;
	for (int outer = 0; outer < arraySize; outer++){
		for(int inner = 0; inner < arraySize-1; inner++){
			if ( *(arrayPtr+inner+1) > *(arrayPtr+inner)){
				temp = *( arrayPtr+inner);
				*(arrayPtr+inner) = *(arrayPtr+inner+1);
				*(arrayPtr+inner+1) = temp;				
			}
		}
	}
}

void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median){
	printf("Minimum: %d \n",min);
	printf("Maximum: %d \n",max);
	printf("Mean: %d \n",mean);
	printf("Median: %d \n",median);
}

