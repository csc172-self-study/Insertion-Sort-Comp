/*
 * InsertionSortComp.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: alex
 */


#include "InsertionSort.h"
#include "DoubleInsertionSort.h"
#include <ctime>
#include <random>
#include <iostream>
using std::cout;

int main() {
	const int SIZE = 11;

	clock_t start;

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<> posDistr(0,SIZE);

	int array[SIZE]; int array1[SIZE]; int array2[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		array[i] = posDistr(eng);
		array1[i] = array[i];
		array2[i] = array[i];
	}

	start = clock();
	InsertionSort<int>(array1, SIZE);
	double orig_sort_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	start = clock();
	DoubleInsertionSort<int>(array2, SIZE);
	double new_sort_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	for (int i = 1; i < SIZE; ++i) {
		if (array1[i] < array1[i-1]) {
			cout << "Array1 was sorted incorrectly.\n";
		}
		if (array2[i] < array2[i-1]) {
			cout << "Array2 was sorted incorrectly.\n";
		}
	}

	cout << "Original method took " << orig_sort_time << " s.\n";
	cout << "New method took " << new_sort_time << " s.\n";
}
