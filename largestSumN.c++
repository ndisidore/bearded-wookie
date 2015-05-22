#include <iostream>
#include <string.h>
// Sum n largest integers in an array of integers where every integer is between 0 and 9

using namespace std;
int SumNLargest( int* anData, int size, int n ) {
	if ( n > size ) {
		return -1;
	} else if ( 0 == n ) {
		return 0;
	}

	// Since only working with 0-9, lets make a temp array and use the num as the index
	int *occurs = new int [10];
	memset( occurs, 0, 10 );

	int numAt;
	// Now loop through our main array and start setting the numbers
	for ( int i = 0; i < size; i++ ) {
		numAt = anData[ i ];
		occurs[ numAt ]++;
	}

	// Now loop backwards and start gathering the sum
	int curSum = 0;
	int curN = n;
	for ( int j = 9; j >= 0; j-- ) {
		numAt = occurs[ j ];
		if ( curN < numAt ) {
			return curSum + ( curN * j );
		}
		curSum += numAt * j;
		curN -= numAt;
	}

	return curSum;
}

int main( ) {
	int tst1[] = { 2, 4, 6, 2, 1, 8, 3, 2, 9 };
	int size1 = (int) sizeof( tst1 ) / sizeof( tst1[0] );
	int maxN1 = 4;
	int res1 = SumNLargest( tst1, size1, maxN1 );
	cout << "Test 1 returns: " << res1;
	return 0;
}