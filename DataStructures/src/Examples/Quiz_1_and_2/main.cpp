#include <iostream>

using namespace std;

template <class T>
class Pair {
	private:
		T fi, se;

	public:
		Pair( ) {};
		void setFirst(T& first) {
			fi = first;
		};
		void setSecond(T& second) {
			se = second;
		};
		void swap( ) {
			T temp = fi;
			fi = se;
			se = temp;
		};
		void print( ) {
			cout << fi << " : " << se << endl;
		};
};

template <class T>
class Pair2 {
	private:
		T first, second;

	public:
		Pair2( ) {}
		void setFirst(T _first) {
			first = _first;
		}
		void setSecond(T _second) {
			second = _second;
		}
		void swap( ) {
			T temp = first;
			first = second;
			second = temp;
		}
		void print( ) {
			cout << first << second << endl;
		}
};

int main( ) {
	Pair<int> pair;
	int x = 2, y = 3;
	pair.setFirst(x);
	pair.setSecond(y);
	pair.print( ); // prints-> 2 : 3;
	pair.swap( );
	pair.print( ); // prints-> 2 : 3;

	Pair<string> pair2;
	string a = "a", b = "b";
	pair2.setFirst(a);
	pair2.setSecond(b);
	pair2.print( ); // prints-> 2 : 3;
	pair2.swap( );
	pair2.print( ); // prints-> 2 : 3;

	return 0;
}

/*
8
8
4
4

methods

cohesive

template

A
B

A









 */