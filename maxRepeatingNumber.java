import java.util.*

/*
http://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time/

Given an array of size n, the array contains numbers in range from 0 to k-1 where k is a positive integer and k <= n. 
Find the maximum repeating number in this array. 
For example, let k be 10 the given array be arr[] = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3}, 
the maximum repeating number would be 2. Expected time complexity is O(n) and extra space allowed is O(1).
Modifications to array are allowed.
*/

//mergesort algorithm

// Runs through the array once, so O(n) running time & O(1) space complexity
public int maxRepeatingNumber( int[] sortedArr ) {
	int maxRepeats = 1, maxRepeated = sortedArr[0];
	int len = sortedArr.length();
	int curValue;
	for ( int i = 1; i < len; i++ ) {
		curValue = sortedArr[ i ];
		if ( curValue === maxRepeated ) {
			// Found another of what's currently being repeated
			maxRepeats++;
		} else {
			// We've got a new value in the sorted array
			// It has to be more than the current number of max repeats or we don't care about it
			if ( ( i + maxRepeats ) < len && ( sortedArr[ i + maxRepeats ] === curValue ) ) {
				// We've got a new max repeated
				maxRepeated = curValue;
				// May as well skip a few elements to save time
				i = i + maxRepeats;
			}
		}
	}

	return maxRepeated;
}

public static void main(String args[]){
    int arr[] = { 2, 2, 1, 3, 1, 2, 0, 3, 0, 0, 0, 4, 5, 4, 4, 4, 4 };
    System.out.println( maxRepeatingNumber( arr ) );
}