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

/**
 * @brief Imports customer data from a filename
 *
 * @param fileName the name and path to the specified file (default - "./data.txt")
 * @return Queue<Customer>
 */
Queue<Customer> readCustomers(string fileName = "./data.txt") {
	Queue<Customer> customers;

	ifstream fileStream(fileName);
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

/**
 * @brief Simulates processing customers in a queue
 *
 */
class Simulation {
	public:
		/** @brief Construct a new Simulation */
		Simulation( );
		/** @brief Runs the simulation */
		void processCustomers(Queue<Customer> customers);
		/** @brief Prints the simulation results */
		void printStatistics( );

	private:
		double maxDelay;
		double averageDelay;
};

#include "Simulation.cpp"

#endif // SIMULATION_H