#include <queue>
#include <vector>

#include "util.h"

struct cashier {
	int customerServing;
	int serveStartTime;
	int serveTime;
	bool currentlyServing = false;
};

bool customerInLines( vector<queue<int> > &lines ) {
	for( int i = 0; i < lines.size( ); i++ )
		if( lines[i].size( ) > 0 )
			return true;
	return false;
}

void getFromLongestLine( vector<queue<int> > &lines, int &customerShortestLine ) {
	queue<int> &longest = lines[0];
	for( int i = 1; i < lines.size( ); i++ )
		if( lines[i].size( ) > longest.size( ) )
			longest = lines[i];
	customerShortestLine = longest.front( );
	longest.pop( );
}

void incrementShortestLine( vector<queue<int> > &lines, int nextCustomer ) {
	queue<int> &shortest = lines[0];
	for( int i = 1; i < lines.size( ); i++ )
		if( lines[i].size( ) < shortest.size( ) )
			shortest = lines[i];
	shortest.push( nextCustomer );
}

int main( ) {
	/*

	You have been hired by a grocery store that is considering switching over from a multiple line set up to a single line setup to handle customers when they check out. Before doing that, they have asked you to simulate if a single line can handle more customers than a multi-line format.

	The last exercise simulated a single line format. For this exercise, you will create a multi-line simulation.

	We will use the same time setup and cashier processing times, but this time you will add customers to one of three cashier lines.

	New customer added every 5 ticks to the shortest queue (starting with cashier 1)
	cashier 1 - checks out a customer from their queue every 12 ticks
	cashier 2 - checks out a customer from their queue every 19 ticks
	cashier 3 - checks out a customer from their queue every 25 ticks
	The starter code prompts the user for the number of customers. Time should start at 1 with 1 customer in the cashier 1 queue. At time = 5, you should at the second customer to the queue (cashier 2 at this point). At time = 10, the third customer is added to cashier 3’s queue. At time = 12, cashier 1 should remove the front of their queue. At time = 15, the shortest queue is cashier 1, so you will add the new customer there. You will continue to add to the queues over time and check out customers as you get to them.

	Remember, you should start looking for the shortest line with cashier 1. If all three have the same length, add to cashier 1’s queue first. If cashier 2 and 3 have the same length, add to cashier 2’s queue.

	Once all customers have been checked out, you should print out the total time needed.

	** Partial Sample Output:**

	How many customers do you want to simulate? 50
	Cashier 1 served customer 1
	Cashier 2 served customer 2
	Cashier 1 served customer 4
	Cashier 3 served customer 3
	...
	Cashier 1 served customer 50
	Cashier 2 served customer 48
	Cashier 3 served customer 49
	It took a total of 301 ticks to serve all customers.

	*/

	int totalCustomers = readInt( "How many customers do you want to simulate? " );
	int time = 0;
	int currentCustomer = 1;

	/*
	 * Sim  1:
	 * New customer every 5 ticks
	 * Central queue
	 * cashier 1 - every 12 ticks
	 * cashier 2 - every 19 ticks
	 * cashier 3 - every 25 ticks
	 *
	 * How long does it take to check out
	 * all customers?
	 */

	vector<queue<int> > lines;
	queue<int> line1, line2, line3;
	line1.push( currentCustomer++ );
	lines.push_back( line1 );
	lines.push_back( line2 );
	lines.push_back( line3 );

	vector<cashier> checkOutStands{ cashier{ 0, 0, 12, false }, cashier{ 0, 0, 19, false }, cashier{ 0, 0, 25, false } };

	while( true ) {
		if( ++time % 5 == 0 && currentCustomer < totalCustomers )
			incrementShortestLine( lines, currentCustomer++ );

		bool checkOutStandsEmpty = true;
		for( int i = 0; i < checkOutStands.size( ); i++ ) {
			cashier &cur = checkOutStands[i];
			if( customerInLines( lines ) && !cur.currentlyServing ) {
				cur.currentlyServing = true;
				getFromLongestLine( lines, cur.customerServing );
				cur.serveStartTime = time;
				cout << "Cashier " << i + 1 << " now serving customer " << cur.customerServing << endl;
			} else if( cur.customerServing && cur.serveStartTime + cur.serveTime == time ) {
				cur.currentlyServing = false;
				// cout << "Cashier " << i + 1 << " served customer " << cur.servingCustomer << endl;
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