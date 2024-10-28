/**
 * @file BoxPM.h
 * @author Sam DePoule
 */

#ifndef BOX_H
#define BOX_H

/**
 * @brief a box class that contains the box's size and volume
 */
class Box {
	public:
		/**
		 * @brief Construct a new Box given `width`, `height`, & `depth`
		 */
		Box(double width, double height, double depth);

		/** @returns the volume of the box */
		double getVolume( ) { return m_width * m_height * m_depth; }

		/** @returns the width of the box */
		double getWidth( ) const { return m_width; }
		/** @brief sets the width of the box to the `newWidth` */
		void setWidth(double newWidth) { m_width = newWidth; }

		/** @returns the height of the box */
		double getHeight( ) const { return m_height; }
		/** @brief sets the height of the box to the `newHeight` */
		void setHeight(double newHeight) { m_height = newHeight; }

		/** * @returns the depth of the box */
		double getDepth( ) const { return m_depth; }
		/** @brief sets the depth of the box to the `newDepth` */
		void setDepth(double newDepth) { m_depth = newDepth; }

		Box& operator+(Box& box);

	private:
		double m_width;
		double m_height;
		double m_depth;
};

#endif // BOX_H