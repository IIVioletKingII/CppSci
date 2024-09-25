#include <iostream>
#include <vector>

using namespace std;

int main( ) {
	int students, days;
	cin >> students;
	cin >> days;

	vector<int> studentTrusts;

	int curInput;

	for( int i = 0; i < students; i++ ) {
		cin >> curInput;
		studentTrusts.push_back( curInput );
	}

	vector<int>::iterator iterator;

	for( int i = 0; i < days; i++ ) {
		int trustLoss;
		cin >> trustLoss;

		int total = 0;
		for( int j = 0; j < studentTrusts.size( ); j++ ) {
			if( studentTrusts[j] > 0 ) {
				total += studentTrusts[j];
				studentTrusts[j] -= trustLoss;
			} else {
				iterator = studentTrusts.begin( ) + j--;
				studentTrusts.erase( iterator );
			}
		}
		cout << studentTrusts.size( ) << " " << total << endl;
	}

	return 0;
}