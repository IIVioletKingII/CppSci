/**
 * @file BoxPM.cpp
 * @author Sam DePoule
 */

#ifndef BOX_CPP
#define BOX_CPP

#include "Box.h"
#include <cmath>

Box::Box(double width, double height, double depth) {
	m_width = width;
	m_height = height;
	m_depth = depth;
}

Box& Box::operator+(Box& box) {
	double totalVolume = this->getVolume( ) + box.getVolume( );
	double length = cbrt(totalVolume);
	return *(new Box(length, length, length));
}

#endif // BOX_CPP