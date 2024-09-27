#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
	private:
		std::string m_make;
		std::string m_model;

	public:
		void printVehicle( );

		std::string getMake( ) { return m_make; };
		void setMake( std::string make ) { m_make = make; }
		std::string getModel( ) { return m_model; };
		void setModel( std::string model ) { m_model = model; }
};

#endif //   VEHICLE_H
