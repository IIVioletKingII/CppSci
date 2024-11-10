/**
 * @file Simulation.h
 */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/* static */ Queue<Customer> readCustomers( ) {
	Queue<Customer> customers;

	string path = "./Data/";
	string fileName = "SampleInput-5.dat";
	ifstream fileStream(path + fileName);
	if( fileStream.is_open( ) ) {

		int numCustomers;
		fileStream >> numCustomers;

		for( int i = 0; i < numCustomers; ++i ) {
			int arrivalTime, helpDuration;
			fileStream >> arrivalTime;
			fileStream >> helpDuration;
			cout << arrivalTime << " " << helpDuration << '\n';
			Customer cus(arrivalTime, helpDuration);
			customers.enqueue(cus);
		}

		fileStream.close( );
	} else
		cout << "Unable to open file";

	return customers;
}