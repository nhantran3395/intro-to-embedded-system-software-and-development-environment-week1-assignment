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

#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void print_array ( unsigned char *arrayPtr, int arraySize){

	#ifdef VERBOSE
	_Bool PRINT_ARRAY_ENABLE=1;
	#else
        _Bool PRINT_ARRAY_ENABLE=0;	
	#endif	
	
	if (PRINT_ARRAY_ENABLE == 1){
		unsigned char *arrayPtrEnd = arrayPtr + arraySize;
		for (;arrayPtr<arrayPtrEnd;++arrayPtr)
		{
			PRINTF("%d ",*arrayPtr);
		}
		PRINTF("\n");
	}
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

