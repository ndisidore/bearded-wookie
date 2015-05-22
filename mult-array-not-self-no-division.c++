#include <iostream>
#include <string.h>
using namespace std;

// Helper method to print out testbench results
void printArray( int arr[], int size, string name ) {
	std::cout << "--Array " << name << "--" << endl;
	std::cout << "[ ";
	for( int i = 0; i < size; i++ ) {
		printf( "%5d", arr[ i ] );
	}
	std::cout << " ]" << endl;
}

// https://www.interviewcake.com/question/product-of-other-numbers
// NO DIVISION (as specified in the problem)
int* get_products_of_all_ints_except_at_index( int orig[], int size ) {
	// Edge case check 
	if ( 0 == size || NULL == orig ) {
		return 0;
	}
	// Build the "before" left array
	int* before = new int[ size ];
	before[ 0 ] = 1;
	int tmp = 1;
	for ( int i = 1; i < size; i++ ) {
		before[ i ] = tmp = tmp * orig[ i - 1 ];
	}
	printArray( before, size, "before" );
	// Build the "after" right array
	int* after = new int[ size ];
	after[ size-1 ] = 1;
	tmp = 1;
	for ( int i = 1; i < size; i++ ) {
		after[ size - i - 1 ] = tmp = tmp * orig[ size - i ];
	}
	printArray( after, size, "after" );
	// Now multiply the two together to get the end result
	int* res = new int[ size ];
	for ( int i = 0; i < size; i++ ) {
		res[ i ] = before[ i ] * after[ i ];
	}
	delete before;
	delete after;
	
	return res;
}

// Main driver/testbench
int main( ) {
	// First test w/ normal inputs
	int test1[] = { 1, 7, 3, 4, 5, 2 };
	int size1 = (int) sizeof( test1 )/sizeof( test1[ 0 ] );
	printArray( test1, size1, "test1" );
	int* res1 = get_products_of_all_ints_except_at_index( test1, size1 );
	printArray( res1, size1, "res1" );

	// Second test w/ zero element
	int test2[] = { 3, 7, 3, 4, 0, 2 };
	int size2 = (int) sizeof( test2 )/sizeof( test2[ 0 ] );
	printArray( test2, size2, "test2" );
	int* res2 = get_products_of_all_ints_except_at_index( test2, size2 );
	printArray( res2, size2, "res2" );
	return 0;
}