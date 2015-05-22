#include <iostream>

using namespace std;

int* zerosToEnd( int arr[], int size ) {
	int numZeros = 0, i;
	for ( i = 0; i < size; i++ ) {
		if ( 0 == arr[i] ) {
			numZeros++;
		} else {
    		// Shift the encountered num by the num of zeros
    		arr[ i - numZeros ] = arr[ i ];
	    }
	}
	cout << "Zeros: " << numZeros << endl << "Size: " << size << endl << "i: " << i << endl;

	// fill in the rest with 0's
    memset( &arr[ i - numZeros ], 0, numZeros );
	return arr;
}

int main()
{
   int test[] = { 1, 0, 4, 0, 3, 0, 0, 1 };
   int* result = zerosToEnd( test, 8 );
   for ( int j = 0; j < 8; j++ ) {
        cout << result[j] << ' ';
    }
}