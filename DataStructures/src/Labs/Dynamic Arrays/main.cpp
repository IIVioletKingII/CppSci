#include <iostream>
#include "DynamicArray.cpp"

int main( ) {
	DynamicArray<int> DA(10);

	for( int i = 0; i < 30; ++i ) {
		DA.add(i);
		std::cout << "add " << i << ":\t" << DA.size( ) << std::endl;
	}

	std::cout << std::endl;

	for( int i = 0; i < 20; ++i )
		std::cout << DA.getByElement(i) << std::endl;

	std::cout << std::endl;

	for( int i = 0; i < 15; ++i )
		DA.removeByElement(10);

	std::cout << std::endl;

	for( int i = 0; i < DA.size( ) + 1; ++i )
		std::cout << i << ":\t" << DA.getByElement(i) << std::endl;

	return 0;
}