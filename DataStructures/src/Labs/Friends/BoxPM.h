/**
 * @file BoxPM.h
 * @author Sam DePoule
 */

#ifndef BOX_PM_H
#define BOX_PM_H

class BoxPM {
	public:
		BoxPM(double width, double height, double depth);

		double getVolume( ) { return m_width * m_height * m_depth; }

		double getWidth( ) const { return m_width; }
		void setWidth(double newWidth) { m_width = newWidth; }

		double getHeight( ) const { return m_height; }
		void setHeight(double newHeight) { m_height = newHeight; }

		double getDepth( ) const { return m_depth; }
		void setDepth(double newDepth) { m_depth = newDepth; }

		/* friend */ BoxPM& operator+(BoxPM& box);

	private:
		double m_width;
		double m_height;
		double m_depth;
};

#include "BoxPM.cpp"

#endif // BOX_PM_H