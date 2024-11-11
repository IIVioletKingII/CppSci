/**
 * @file Simulation.h
 * @author Sam DePoule
 */


#ifndef SIMULATION_H
#define SIMULATION_H

#include <fstream>
#include <iostream>
#include <string>

#include "Customer.h"
#include "Queue.h"

using namespace std;

Queue<Customer> readCustomers(string fileNum = "1") {
	Queue<Customer> customers;

	string path = "./Data/";
	string fileName = "SampleInput-" + fileNum + ".dat";
	ifstream fileStream(path + fileName);
	if( fileStream.is_open( ) ) {

		int numCustomers;
		fileStream >> numCustomers;
		// cout << numCustomers << endl;

		for( int i = 0; i < numCustomers; ++i ) {
			int arrivalTime, helpDuration;
			fileStream >> arrivalTime;
			fileStream >> helpDuration;
			// cout << arrivalTime << " " << helpDuration << endl;
			Customer cus(arrivalTime, helpDuration);
			customers.enqueue(cus);
		}

		fileStream.close( );
	} else
		cout << "Unable to open file" << endl;

	return customers;
}

class Simulation {
	public:
		Simulation( );
		void processCustomers(Queue<Customer> customers);
		void printStatistics( );

	private:
		double maxDelay;
		double averageDelay;
};

#include "Simulation.cpp"

#endif // SIMULATION_H