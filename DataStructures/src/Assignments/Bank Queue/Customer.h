/**
 * @file Customer.h
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

class Customer {
	public:
		/**
		 * @brief Constructs a new Customer with their arrival time and help duration
		 */
		Customer( ) {
			m_arrivalTime = m_helpDuration = -1;
		};
		/**
		 * @brief Constructs a new Customer with their arrival time and help duration
		 *
		 * @param arrival the arrival time in seconds
		 * @param helpTime the help duration in seconds
		 */
		Customer(int arrival, int helpTime) {
			m_arrivalTime = arrival;
			m_helpDuration = helpTime;
		};

		/**
		 * @brief Sets the arrival time of the customer
		 * @param arrival the new arrival time in seconds
		 */
		void setArrivalTime(int arrival) {
			m_arrivalTime = arrival;
		};
		/** @brief Returns the arrival time of the customer */
		int getArrivalTime( ) { return m_arrivalTime; };

		/**
		 * @brief Sets the help duration of the customer
		 * @param helpTime the new help duration in seconds
		 */
		void setHelpDuration(int helpTime) {
			m_helpDuration = helpTime;
		};
		/** @brief Returns the help duration of the customer */
		int getHelpDuration( ) { return m_helpDuration; };

		friend std::ostream& operator<<(std::ostream& os, const Customer& cus) {
			return (os << cus.m_arrivalTime << " " << cus.m_helpDuration);
		};

	private:
		int m_arrivalTime;
		int m_helpDuration;
};

#endif // CUSTOMER_H