/**
 * @file main.cpp
 * @author Sam DePoule
 */

#include <iostream>
#include "BoxPM.h"

int main( ) {
	BoxPM box1(2, 3, 4);
	BoxPM box2(2, 3, 4);

	BoxPM box3 = box1 + box2;

	std::cout << box3.getVolume( ) << std::endl;

	return 0;
}