#include <iostream>

using namespace std;

int main()
{
	/* Strings have a find function, but unlike other
	 * languages that return -1 when not found, C++
	 * returns the string npos.
	 */

	string str = "alley cat";
	if (str.find("cat") != string::npos)
	{
		cout << "I found a cat!" << endl;
	}

	/* C++ allows us to assign values within our
	 * conditional statement. Notice in this example
	 * how we assign a value in the condition, then
	 * use it in the statement block
	 */

	int found = 0;
	while ((found = str.find("a", found)) != string::npos)
	{
		str.replace(found, 1, "@");
	}
	cout << str << endl;

	return 0;
}