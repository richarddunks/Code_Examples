/*	@desc	A program to test a counter increment plan
*			to facilitate multiplication of two integer arrays
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	cout << setw( 10 ) << "Value of j" 
		<< setw( 10 ) << "Value of i"
		<< setw( 10 ) << "Value of k" 
		<< setw( 10 ) << "Value of --j" << endl;
		
	for ( int i = 10; i > 5; i-- )
	{
		int k = i;
		int j = 10;
		while ( j > 5 )
		{

			cout << setw( 10 ) << j
				<< setw( 10 ) << i
				<< setw( 10 ) << k;
			cout << setw( 10 ) << --j
				<< endl;
			k--;	
		}
	}
} //end function main