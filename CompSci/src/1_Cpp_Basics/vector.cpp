#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> fruit;
	// Add element to the end  of a vector
	fruit.push_back("orange");
	fruit.push_back("strawberry");

	// You can also create with default values
	vector<int> grades{96, 99, 93, 88};

	/* You can access an element to get the value
	 * using the .at(index) command, however if
	 * the idex is out of range, you will get an
	 * error. A safer way to access elements is to
	 * use the []. If the index doesn't exist,
	 * an error is not usually thrown (but can
	 * occur sometimes).
	 */

	// only 2 elements, so nothing in index 2
	// This may crash your program or may provide garbage results
	// cout << fruit[2] << endl;

	// uncomment the line below to see the error
	// cout << fruit.at(2) << endl;

	// You can use the [] to update a values
	fruit[1] = "banana";
	cout << fruit[1] << endl;

	// You can also use .at() to update values
	grades.at(3) = 92;
	cout << grades[3] << endl;

	return 0;
}