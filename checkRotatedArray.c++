#include <iostream>

// Given 2 integer arrays, determine of the 2nd array is a rotated version of the 1st array.
// Ex. Original Array A={1,2,3,5,6,7,8} Rotated Array B={5,6,7,8,1,2,3}

using namespace std;

bool checkRotated( int arrA[], int sizeA, int arrB[], int sizeB ) {
	// First check sizes
	if ( sizeA != sizeB || sizeA == 0 || sizeB == 0 ) {
		return false;
	}

	// Var setup
	int bStart = 0;
	int bProg = 0;
	int aProg = 0;
	bool loopedFlag = false;
	while ( true ) {
		//cout << endl <<"bProg: " << bProg << " val:" << arrB[ bProg ] << endl;
		//cout << "aProg: " << aProg << " val:" << arrA[ aProg ] << endl;
		// Check if the current element is the first in our 'A' array
		if ( arrB[ bProg ] == arrA[ aProg ] ) {
			if ( aProg == sizeA - 1 ) {
				return true;
			}
			aProg++;
		} else {
			// Else make sure aProg is 0
			aProg = 0;
			if ( loopedFlag ) {
				return false;
			}
		}
		// now increment our current spot on B
		if ( bProg >= sizeB - 1 ) {
			//cout << "bProg reset" << endl;
			bProg = 0;
			loopedFlag = true;
		} else {
			bProg++;
		}
	}

	return false;
}

int main() {
	int tst1a[] = { 1, 2, 3, 5, 6, 7,8 };
	int tst1b[] = { 5, 6, 7, 8, 1, 2, 3 };
	int size1 = (int) sizeof( tst1a ) / sizeof( tst1a[ 0 ] );
	bool res1 = checkRotated( tst1a, size1, tst1b, size1 );
	cout << "Test 1 returns: " << res1 << endl;
}
