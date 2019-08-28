/*
 * DoubleInsertionSort.h
 *
 *  Created on: Jul 22, 2019
 *      Author: alex
 */

#ifndef DOUBLEINSERTIONSORT_H_
#define DOUBLEINSERTIONSORT_H_

#include "ArrayOperations.h"

template <typename E>
void DoubleInsertionSort(E array[], int size) {
	int topRight, botLeft;
	if (size % 2 == 0) {
		topRight = size/2;
		botLeft = topRight - 1;
	} else {
		topRight = size/2 + 1;
		botLeft = size/2 - 1;
	}

	for (int i = topRight, j = botLeft; i < size; ++i, --j) {
		topRight = i; botLeft = j;
		if (array[topRight] < array[botLeft]) {
			swap(array, topRight, botLeft);
		}
		while (array[botLeft] > array[botLeft + 1]) {
			swap(array, botLeft, botLeft + 1);
			++botLeft;
		}
		while (array[topRight] < array[topRight - 1]) {
			swap(array, topRight, topRight - 1);
			--topRight;
		}
	}
}



#endif /* DOUBLEINSERTIONSORT_H_ */
