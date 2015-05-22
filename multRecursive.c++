#include <iostream>

// Write a multiply function that multiples 2 integers without using *

using namespace std;

int doRecursiveMultiply( int base, int by ) {
	if ( 0 === by ) {
		return 0;
	} else if ( 1 == by ) {
		retrun 1;
	}

	return base + doRecursiveMultiply( base, by - 1 );
}

int main( ) {
	int base[] = { 5, 2, 6, 1, 8, 22, 10 };
	int by[]   = { 4, 6, 6, 9, 0, 2, 1 };
	int res = 0;

	for ( int i = 0; i < 6; i++ ) {
		res = doRecursiveMultiply( base[ i ], by[ i ] );
		cout << base[i] << " *  " << by[i] << " = " << res << endl;
	}
}