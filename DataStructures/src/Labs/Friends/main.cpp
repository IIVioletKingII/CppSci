/**
 * @file main.cpp
 * @author Sam DePoule
 */

#include <iostream>
#include "Box.h"

int main( ) {
	Box box1(2, 3, 4);
	Box box2(2, 3, 4);

	Box box3 = box1 + box2;

	std::cout << box3.getVolume( ) << std::endl;

	return 0;
}