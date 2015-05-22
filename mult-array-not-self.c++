#include <iostream>
//Given an array, return a new array which has multiplication of all elements except own index

using namespace std;

int* multiplyAllExceptOwn( int orig[], int size ) {
	int mult = 1;
	bool zeroFlag = false, twoPlusZeros = false;
	// Lets first find the total multiplied value by looping once through the array
	for ( int i = 0; i < size; i++ ) {
		// We hit zero. don't want to ruin it for the rest of the array
		if ( orig[ i ] == 0 ) {
			if ( zeroFlag ) {
				// If we have 2 or more zeros, everything will be zero
				twoPlusZeros = true;
				break;
			}
			zeroFlag = true;
		} else {
			mult = mult * orig[ i ];
		}
	}

	// Lets create the new array
	int* newMult = new int[size];

	// Special case for twoPlusZeros
	if ( twoPlusZeros ) {
		memset( newMult, 0, size );
		return newMult;
	}

	// mult should now be our multiplied value
	for ( int j = 0; j < size; j++ ) {
		if ( orig[ j ] == 0 ) {
			newMult[ j ] = mult;
		} else if ( zeroFlag ) {
			newMult[ j ] = 0;
		} else {
			newMult[ j ] = mult / orig[ j ];
		}
	}
	// Return the new multiplied array
	return newMult;
}

int main() {
	int i;
	int tst1[] = { 2, 4, 6, 2, 1 };
	int size1 = (int) sizeof( tst1 ) / sizeof( tst1[0] );
	int* res1 = multiplyAllExceptOwn( tst1,  size1);
	int tst2[] = { 5, 2, 1, 0, 3 , 3 };
	int size2 = (int) sizeof( tst2 ) / sizeof( tst2[0] );
	int* res2 = multiplyAllExceptOwn( tst2, size2 );
	int tst3[] = { 5, 2, 1, 0, 3 , 3, 0 };
	int size3 = (int) sizeof( tst3 ) / sizeof( tst3[0] );
	int* res3 = multiplyAllExceptOwn( tst3, size3 );
	cout << "TEST1: " << endl;
	for ( i = 0; i < size1; i++ ) {
		cout << res1[ i ] << " ";
	}
	cout << endl << "TEST2: " << endl;
	for ( i = 0; i < size2; i++ ) {
		cout << res2[ i ] << " ";
	}
	cout << endl << "TEST3: " << endl;
	for ( i = 0; i < size3; i++ ) {
		cout << res3[ i ] << " ";
	}
}