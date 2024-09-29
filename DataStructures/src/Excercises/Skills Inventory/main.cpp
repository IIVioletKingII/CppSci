#include <iostream>
using namespace std;

class LegoBrick {
	private:
		int part_number;
		string type;
		string color;
		int width;
		int depth;
		int height;

	public:
		LegoBrick(int pN, string t = "Brick", string c = "Black", int w = 1, int d = 1, int h = -1) {
			part_number = pN;
			type = t;
			color = c;
			if( h == -1 ) {
				if( t == "Brick" )
					height = 3;
				else if( t == "Plate" || t == "Tile" )
					height = 1;
				else
					height = 1;
			} else {
				height = h;
			}
			width = w;
			depth = d;
		}

		// part_number getter & setter
		int getPartNumber( ) { return part_number; };
		void setPartNumber(int new_part_number) { part_number = new_part_number; }

		// type getter & setter
		string getType( ) { return type; };
		void setType(string new_type) { type = new_type; }

		// color getter & setter
		string getColor( ) { return color; };
		void setColor(string new_color) { color = new_color; }

		// part_number getter & setter
		int getWidth( ) { return width; };
		void setWidth(int new_width) { width = new_width; }

		// part_number getter & setter
		int getDepth( ) { return depth; };
		void setDepth(int new_depth) { depth = new_depth; }

		// part_number getter & setter
		int getHeight( ) { return height; };
		void setHeight(int new_height) { height = new_height; }

		string toString( ) {
			return "Part number #" + to_string(part_number) + ": " + color + " " + type + " " + to_string(width) + "x" + to_string(depth);
		}
		void print( ) {
			cout << toString( );
		}
};

int main( ) {
	LegoBrick black2x1Brick(3004, "Brick", "Black", 1, 2);
	LegoBrick green2x3Plate(3021, "Plate", "Green", 3, 2);

	black2x1Brick.print( );
	green2x3Plate.print( );

	return 0;
}