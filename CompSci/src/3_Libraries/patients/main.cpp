#include <vector>

#include "util.h"

struct patient {
	string name;
	double temp;
};

int main( ) {
	// Enter your code here

	/*
	A local mall has implemented a temperature check point to make sure that everyone that enters is healthy. To help assist them, you are going to create a record of all the patients that are coming in to be screened so that the mall knows who is eligible to attend.

	Create a patient struct that stores name and temperature. Patient name should be stored as all caps and temperature should be between 95 and 106.

	Prompt the user for patient name and temp and then store them in a vector. After all the names are entered, loop through the array and print out all eligible patients. A patient is eligible if their temperature is below 100.

	Sample Output:

	Please enter the patient's name ('exit' when done): Cassandra
	Please enter their temperature: 98.6
	Please enter the patient's name ('exit' when done): Jackson
	Please enter their temperature: 90.2
	Temperature should be between 95 and 106: 99
	Please enter the patient's name ('exit' when done): Jamal
	Please enter their temperature: 100.3
	Please enter the patient's name ('exit' when done): exit
	The following patients may attend:
	CASSANDRA
	JACKSON
	*/

	vector<patient> patients;

	string input = "";

	do {
		input = readLine( "Please enter the patient's name ('exit' when done): " );
		double temp = readDouble( 95, 106, "Please enter their temperature: ", "Temperature should be between 95 and 106: " );
		patients.push_back( patient{ input, temp } );
	} while( input != "exit" );

	cout << "The following patients may attend:" << endl;
	for( int i = 0; i < patients.size( ); i++ )
		if( patients[i].temp < 100 )
			cout << toUpperCase( patients[i].name ) << endl;

	return 0;
}