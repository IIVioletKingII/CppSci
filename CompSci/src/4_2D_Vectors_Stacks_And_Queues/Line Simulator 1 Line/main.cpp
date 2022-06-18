#include <queue>
#include <vector>

#include "util.h"

struct cashier {
	int customerServing;
	int serveStartTime;
	int serveTime;
	bool currentlyServing = false;
};

int main( ) {
	/*

	You have been hired by a grocery store that is considering switching over from a multiple line set up to a single line setup to handle customers when they check out. Before doing that, they have asked you to simulate if a single line can handle more customers than a multi-line format.

	Over the next two exercises, you are going to create these two simulations. For this exercise, you will create a single-line simulation.

	To help simulate this, we will use a time variable and a loop.

	New customer added every 5 ticks to a central queue
	cashier 1 - checks out a customer every 12 ticks
	cashier 2 - checks out a customer every 19 ticks
	cashier 3 - checks out a customer every 25 ticks
	The starter code prompts the user for the number of customers. Time should start at 1 with 1 customer in the queue. At time = 5, you should at the second customer to the queue. At time = 10, the third customer is added. At time = 12, cashier 1 should remove the front of the queue. You will continue to add to the queue every 5 ticks and remove from the queue every 12, 19, and 25 ticks until all customers have been added to the queue and removed by a cashier.

	Once all customers have been checked out, you should print out the total time needed.

	** Partial Sample Output:**

	How many customers do you want to simulate? 50
	Cashier 1 served customer 1
	Cashier 2 served customer 2
	Cashier 1 now serving customer 3
	Cashier 3 now serving customer 4
	...
	Cashier 1 served customer 48
	Cashier 2 served customer 49
	Cashier 1 served customer 50
	It took a total of 289 ticks to serve all customers.

	*/

	int totalCustomers = readInt( "How many customers do you want to simulate? " );
	int time = 0;
	int currentCustomer = 1;

	/* Sim  1:
	 * New customer every 5 ticks
	 * Central queue
	 * cashier 1 - every 12 ticks
	 * cashier 2 - every 19 ticks
	 * cashier 3 - every 25 ticks
	 *
	 * How long does it take to check out
	 * all customers?
	 */

	queue<int> line;
	line.push( 1 );

	vector<cashier> checkOutStand{ cashier{ 0, 0, 12, false }, cashier{ 0, 0, 19, false }, cashier{ 0, 0, 25, false } };

	while( true ) {
		if( ++time % 5 == 0 && currentCustomer < totalCustomers )
			line.push( ++currentCustomer );

		bool checkOutStandsEmpty = true;
		for( int i = 0; i < checkOutStand.size( ); i++ ) {
			cashier &cur = checkOutStand[i];
			if( line.size( ) > 0 && !cur.currentlyServing ) {
				cur.currentlyServing = true;
				cur.customerServing = line.front( );
				cur.serveStartTime = time;
				line.pop( );
				cout << "Cashier " << i + 1 << " now serving customer " << cur.customerServing << endl;
			} else if( cur.customerServing && cur.serveStartTime + cur.serveTime == time ) {
				cur.currentlyServing = false;
				cout << "Cashier " << i + 1 << " served customer " << cur.customerServing << endl;
			}
			if( cur.currentlyServing )
				checkOutStandsEmpty = false;
		}
		if( currentCustomer == totalCustomers && checkOutStandsEmpty )
			break;
	}

	cout << "It took a total of " << time << " ticks to serve all customers." << endl;

	return 0;
}