#include <iostream>

using namespace std;

int main( ) {
	// To read a single word, you can use the cin command
	cout << "Please enter a number of seconds:" << endl;
	int inputSeconds;
	cin >> inputSeconds;

	int seconds = inputSeconds;

	constexpr int secondsInMinute = 60;
	constexpr int secondsInHour = secondsInMinute * 60;
	constexpr int secondsInDay = secondsInHour * 24;

	int days = seconds / secondsInDay;
	seconds -= days * secondsInDay;
	int hours = seconds / secondsInHour;
	seconds -= hours * secondsInHour;
	int minutes = seconds / secondsInMinute;
	seconds -= minutes * secondsInMinute;

	// Example: 3,661 second(s) is equivalent to 0 day(s), 1 hour(s), 1 minute(s), and 1 second(s).
	cout << inputSeconds << " second(s) is equivalent to " << days << " day(s), " << hours << " hour(s), " << minutes << " minute(s), and " << seconds << " second(s)." << endl;

	return 0;
}
