#include <fstream>
#include <iostream>
#include "Customer.h"
#include "Queue.h"
#include "Simulation.h"

int main( ) {
	// Queue<Customer> bankCustomers = readCustomers();   // Read the list of customers and arrival times from a file
	// Simulation bankSimulation;
	// std::cout << "Processing Customers:" << std::endl;
	// bankSimulation.processCustomers(bankCustomers);     // Simulates the teller serving the customers in the queue
	// bankSimulation.printStatistics();                   // Prints out the maxium delay and the average delay



	// Queue<Customer> bankCustomers;
	// Customer cus1(2, 3);
	// Customer cus2(4, 6);
	// Customer cus3(5, 8);
	// bankCustomers.enqueue(cus1);
	// bankCustomers.enqueue(cus2);
	// bankCustomers.enqueue(cus3);

	Queue<Customer> bankCustomers = readCustomers( );

	// std::cout << "Cus1: " << cus1 << std::endl;

	std::cout << "Cus1: " << bankCustomers.dequeue( ) << std::endl;
	bankCustomers.print( );

	return 0;
}