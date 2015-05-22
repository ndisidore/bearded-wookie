#include <iostream>
//Given an array, find maximum of all subarrays of size k

using namespace std;

int maxSubArrayofK( int arr[], int n, int k ) {
	if ( k > n ) {
		// Desired length bigger than target array
		return -1;
	}

	int first = 0, last = 0, curTotal, curMax = 0;
	// Progress k along, dropping first element and adding last element
	for ( int i = 0; i < k; i++ ) {
		curTotal += arr[ i ];
	}

	for ( int i = k; i < n; i++ ) {
		cout << "First: " << first << " - Last: " << i << " - curTotal : " << curTotal << endl;
		// The Meat
		// Drop first element and add on the last
		curTotal = curTotal - arr[ first ] + arr[ i ];
		// And see if that makes a new max
		if ( curTotal > curMax ) {
			curMax = curTotal;
		}
		first++;
	}

	// Finally return the max we found
	return curMax;
}

int main() {
	int maxK = 4;
	int tst1[] = { 2, 4, 6, 2, 1, 8, 3, 2, 9 };
	int size1 = (int) sizeof( tst1 ) / sizeof( tst1[0] );
	int res1 = maxSubArrayofK( tst1,  size1, maxK );
	// Print out
	cout << "Max Size of subarray " << maxK << ": " << res1 << endl;
}