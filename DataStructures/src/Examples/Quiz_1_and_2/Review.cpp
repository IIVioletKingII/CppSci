#include <iostream>

template <typename T>
T getMax(T x, T y) {
	return (x > y) ? x : y;
}

void passByValue(int value) {
	value *= 10;
	std::cout << "Value (Function): " << value << std::endl;
}

void passByReference(int& reference) {
	reference *= 10;
	std::cout << "Reference (Function): " << reference << std::endl;
}

void pointerFunction( ) {
	int* pVarOne;
	int* pVarTwo;
	int** pVarThree;

	int var = 42;

	std::cout << "var - Value of variable: " << var << std::endl;
	std::cout << "&var - Address of variable: " << &var << std::endl
						<< std::endl;

	pVarOne = &var;

	std::cout << "pVarOne - Address of var: " << pVarOne << std::endl;
	std::cout << "*pVarOne - Value of var: " << *pVarOne << std::endl;
	std::cout << "&pVarOne - Address of pVarOne: " << &pVarOne << std::endl
						<< std::endl;
	;

	pVarTwo = pVarOne;

	std::cout << "pVarTwo - Address of var: " << pVarTwo << std::endl;
	std::cout << "*pVarTwo - Value of var: " << *pVarTwo << std::endl;
	std::cout << "&pVarTwo - Address of pVarTwo: " << &pVarTwo << std::endl
						<< std::endl;

	pVarThree = &pVarTwo;

	std::cout << "pVarThree - Address of pVarTwo: " << pVarThree << std::endl;
	std::cout << "*pVarThree - Address of var: " << *pVarThree << std::endl;
	std::cout << "&pVarThree - Address of pVarThree: " << &pVarThree << std::endl
						<< std::endl;

	std::cout << "------------------------------------------------------" << std::endl
						<< std::endl;
}

int main( ) {
	int value = 10;
	int reference = 50;

	std::cout << "Value Before Calling Function (Main): " << value << std::endl;
	passByValue(value);
	std::cout << "Value (Main): " << value << std::endl
						<< std::endl;

	std::cout << "Reference Before Calling Function (Main): " << reference << std::endl;
	passByReference(reference);
	std::cout << "Reference (Main): " << reference << std::endl
						<< std::endl;

	std::cout << "------------------------------------------------------" << std::endl
						<< std::endl;

	pointerFunction( );

	std::cout << "Call as int: " << getMax<int>(3, 7) << std::endl;
	std::cout << "Call as double: " << getMax<double>(3.0, 7.0) << std::endl;
	std::cout << "Call as char: " << getMax<char>('g', 'e') << std::endl
						<< std::endl;

	std::cout << "------------------------------------------------------" << std::endl
						<< std::endl;

	return 0;
}