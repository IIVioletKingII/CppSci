#include <iostream>
#include "QuickSort.h"

const int arrSize = 10;


void print(int arr[]) {
	for( int i = 0; i < arrSize; ++i )
		std::cout << arr[i] << (i < arrSize - 1 ? ", " : "");
	std::cout << std::endl;
}

int main( ) {
	int arr[arrSize];

	for( int i = arrSize, j = 0; i > 0; --i, ++j )
		arr[j] = i;

	// arr[0] = 1;
	// arr[1] = 2;
	// arr[2] = 4;
	// arr[3] = 3;
	// arr[4] = 5;
	// arr[5] = 6;
	// arr[6] = 7;
	// arr[7] = 9;
	// arr[8] = 10;
	// arr[9] = 8;


	print(arr);

	QuickSort quickSorter;
	quickSorter.sort(arr, arrSize);

	print(arr);

	return 0;
}