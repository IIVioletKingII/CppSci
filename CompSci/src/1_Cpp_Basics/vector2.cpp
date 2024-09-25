#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> sports{"Field Hockey", "Volleyball", "Basketball"};

	/* While vectors can be accessed directly by
	 * index value, to insert, we need to reference
	 * an iterator value.
	 */

	// Create the iterator and assigning to the begining
	vector<string>::iterator it = sports.begin();

	/* To insert at a position, you can reference the
	 * position relative to the iterator
	 */

	// Insert at the begining
	sports.insert(it, "Lax");

	/* After inserting, the begining iterator
	 * is no longer valid and needs to be reset.
	 */
	it = sports.begin();

	// Insert at index 2
	sports.insert(it + 2, "Softball");

	for (string sport : sports)
	{
		cout << sport << endl;
	}

	return 0;
}