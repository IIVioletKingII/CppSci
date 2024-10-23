/**
 * @file BoxPM.cpp
 * @author Sam DePoule
 */

#include "BoxPM.h"
#include <cmath>

BoxPM::BoxPM(double width, double height, double depth) {
	m_width = width;
	m_height = height;
	m_depth = depth;
}


BoxPM& BoxPM::operator+(BoxPM& box) {
	double totalVolume = this->getVolume( ) + box.getVolume( );
	double length = cbrt(totalVolume);
	// double newWidth = this->m_width + box.m_width;
	// double newHeight = this->m_height + box.m_height;
	// double newDepth = this->m_depth + box.m_depth;
	return *(new BoxPM(length, length, length));
}