/**
 * @file QuickSort.cpp
 * Created by gordon.gul on 10/31/2024.
 * Modified by samuel.depoule on 11/01/2024.
 */

#include "QuickSort.h"

void QuickSort::sort(int unsortedArray[], int size) {
	sort(unsortedArray, 0, size - 1);
}

void QuickSort::sort(int unsortedArray[], int leftBoundIndex, int rightBoundIndex) {
	if( leftBoundIndex < rightBoundIndex ) {
		int leftIndex = leftBoundIndex;
		int rightIndex = rightBoundIndex;
		int pivotVal = unsortedArray[(leftBoundIndex + rightBoundIndex) / 2];

		while( leftIndex <= rightIndex ) {
			while( unsortedArray[leftIndex] < pivotVal )
				++leftIndex;

			while( pivotVal < unsortedArray[rightIndex] )
				--rightIndex;

			if( leftIndex <= rightIndex )
				swap(unsortedArray, leftIndex++, rightIndex--);
		}

		sort(unsortedArray, leftBoundIndex, leftIndex - 1);
		sort(unsortedArray, leftIndex, rightBoundIndex);
	}
}

void QuickSort::swap(int unsortedArray[], int leftIndex, int rightIndex) {
	int tempElement = unsortedArray[leftIndex];

	unsortedArray[leftIndex] = unsortedArray[rightIndex];
	unsortedArray[rightIndex] = tempElement;
}