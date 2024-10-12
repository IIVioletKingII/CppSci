#include <iostream>
#include <string>
#include "LinkedList.cpp"

int main( ) {
	LinkedList<int> LLInt;
	LLInt.add(100);
	LLInt.add(200);
	LLInt.add(300);
	LLInt.add(400);

	for( int i = 0; i < LLInt.getSize( ); ++i ) {
		std::cout << LLInt.getByIndex(i) << std::endl;
	}

	std::cout << std::endl;

	LLInt.deleteByIndex(1);

	for( int i = 0; i < LLInt.getSize( ); ++i ) {
		std::cout << LLInt.getByIndex(i) << std::endl;
	}

	std::cout << std::endl;

	LLInt.deleteByValue(300);

	for( int i = 0; i < LLInt.getSize( ); ++i ) {
		std::cout << LLInt.getByIndex(i) << std::endl;
	}

	std::cout << std::endl;

	LinkedList<std::string> LLString;
	LLString.add("One Hundred");
	LLString.add("Two Hundred");
	LLString.add("Three Hundred");
	LLString.add("Four Hundred");

	for( int i = 0; i < 4; ++i ) {
		std::cout << LLString.getByIndex(i) << std::endl;
	}
}