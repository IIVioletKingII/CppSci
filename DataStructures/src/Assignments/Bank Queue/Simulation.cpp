/**
 * @file Simulation.cpp
 */

#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include "Simulation.h"
#include "Customer.h"
#include "Queue.h"

Simulation::Simulation( )
		: maxDelay(0), averageDelay(0) {
}

void Simulation::processCustomers(Queue<Customer> customers) {
	if( customers.isEmpty( ) ) {
		maxDelay = -1;
		averageDelay = -1;
	} else {
		int length = 0, delay = 0;
		maxDelay = averageDelay = 0;
		while( !customers.isEmpty( ) ) {
			++length;
			Customer cus = customers.dequeue( );
			// std::cout << "removed from queue: " << cus << std::endl;
			int arrTime = cus.getArrivalTime( );
			int helpDur = cus.getHelpDuration( );

			int cusDelay = length == 1 ? 0 : (delay - arrTime);
			if( cusDelay > maxDelay )
				maxDelay = cusDelay;
			delay += helpDur;
			averageDelay += cusDelay;
		}
		averageDelay /= length;
	}
}

void Simulation::printStatistics( ) {
	std::cout << "Max Delay = " << maxDelay << std::endl; // final customer's total wait time
	std::cout << "Average Delay = " << averageDelay << std::endl;
}

#endif // SIMULATION_CPP