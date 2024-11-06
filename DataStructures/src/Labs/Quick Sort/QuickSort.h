/**
 * @file QuickSort.h
 * Created by gordon.gul on 10/31/2024.
 * Modified by samuel.depoule on 11/01/2024.
 */

#ifndef QUICKSORTPM_H
#define QUICKSORTPM_H

class QuickSort {
	public:
		/**
		 * @brief quick sorts the given array
		 */
		/* static  */ void sort(int unsortedArray[], int size);

	private:
		/**
		 * @brief recursively sorts array using the swap method
		 */
		/* static  */ void sort(int unsortedArray[], int leftBoundIndex, int rightBoundIndex);
		/**
		 * @brief swaps the values of two positions in an array
		 */
		/* static  */ void swap(int unsortedArray[], int leftIndex, int rightIndex);
};

#endif // QUICKSORTPM_H
