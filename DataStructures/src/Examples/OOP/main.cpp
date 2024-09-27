#include "Vehicle.cpp"
#include "Vehicle.h"

int main( ) {
	Vehicle myVehicle;

	myVehicle.setMake("Volvo");
	myVehicle.setModel("343");

	myVehicle.printVehicle( );

	return 0;
}