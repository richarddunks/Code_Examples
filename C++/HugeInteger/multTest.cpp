/* @desc	A program to test the multiplication of values from 
*			two arrays
*  @author	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

int main()
{
	//variable declarations
//	int operand1[ ARRAY_SIZE ] = { 0,0,0,0,0,2,2,2,2,2 };
//	int operand2[ ARRAY_SIZE ] = { 0,0,0,0,0,2,2,2,2,2 };
	int operand4[ ARRAY_SIZE ] = { 0,0,0,0,0,3,6,7,8,9 };
	int operand5[ ARRAY_SIZE ] = { 0,0,0,0,0,7,1,2,3,4 };

	int product[ ARRAY_SIZE ] = { 0 };
	
	//function prototypes
	void multiplication( int opr1[], int opr2[], int product[] ); //multiply HugeInts
	void display( int array[] ); //display array
	
	cout << "Operand4 = ";
	display( operand4 );
	cout << "Operand5 = ";
	display( operand5 );
	cout << "Product = ";
	display( product );

	multiplication( operand4, operand5, product ); //pass operands to be multiplied

	cout << "Operand4 = ";
	display( operand4 );
	cout << "Operand5 = ";
	display( operand5 );
	cout << "Product = ";
	display( product );


} //end function main

//begin function definitions
void multiplication( int opr1[], int opr2[], int product[] ) //multiply HugeInts
{
/* @desc	A function to multiply the elements of HugeInteger data member with a 
*			passed HugeInteger object. The first for loop (i-controlled) loops
*			through operand2 while the second for loop (j-controlled) loops through
* 			operand1. Index k, initialized in the beginning of the i-controlled for loop,  
*			controls the placement of the multiplication result in the proper
*			place of the product array, which shifts with each iteration through
*			the j-controlled loop. The tens result is placed in the next location of the
*			carryover array before the next addition operation commences. The carryover
*			array is re-initialized after the completion of each j-controlled loop.
*			The resulting product array contains two-digit integers (overflow) that
*			are "cleaned up" in the second for loop (k-controlled) in order to create
*			the proper result.
* @pre		One HugeInteger object is passed to be multiplied to the data member of
*			the object.
* @post		The product is returned as a HugeInteger object containing the result
*			of the multiplication operation.
* @author	Richard Dunks richarddunks@gmail.com
*/
	for ( int i = ARRAY_SIZE - 1; i >= 0; i--) //loop through operand2
	{
		int k = i; //index value for product array
		int carryover[ ARRAY_SIZE ] = { 0 }; //reinitialize carryover array to 0 each pass through inner loop
//		int j = ARRAY_SIZE - 1; //index for inner loop
		for ( int j = ARRAY_SIZE - 1; j >= 0; j-- ) //loop through operand1
		{
			int result = ( opr1[ j ] * opr2[ i ] ) + carryover[ j ]; //raw calculation
			product[ k ] += result % 10; //ones digit of multiplication result
			carryover[ (j - 1) ] = result / 10; //assignment of carryover value and predecrement index
			k--; //decrement product index for next pass through loop
		} //end for loop through operand1

		cout << "The carryover value is: ";
		{ //display carryover array
			int i = 0;
			cout << "Carryover = ";
			while ( carryover[ i ] == 0 && i < (ARRAY_SIZE - 1) ) //find start of number through leading zeros
			{
				i++;
			} //end while
			
			while ( i < ARRAY_SIZE )
			{
				cout <<carryover[ i ];
				i++; //increment counter
			} //end while
			cout << endl;
		} //end function display

		cout << endl;
	} //end for loop through operand2

	//clean up overflow in product array
	int carryover[ ARRAY_SIZE ] = { 0 }; //carryover array
	for ( int k = ARRAY_SIZE - 1; k >= 0; k--)
	{
		int i = k - 1; //advance increment for carryover
		if ( product[ k ] > 9 || carryover[ k ] != 0 ) //test for product array value >9 or carryover value
		{	
			int result = product[ k ] + carryover [ k ];

			product[ k ] = result % 10;			
			carryover[ i ] = result / 10;
		} //end if
	} //end for loop to clean up product overflow

	{ //display carryover array
		int i = 0;
		cout << "Carryover = ";
		while ( carryover[ i ] == 0 ) //find start of number through leading zeros
		{
			i++;
		} //end while
		
		while ( i < ARRAY_SIZE )
		{
			cout <<carryover[ i ];
			i++; //increment counter
		} //end while
		cout << endl;
	} //end function display


} //end function multiplication


void display( int array[] ) //display array
{
	int i = 0;
	
	while ( array[ i ] == 0 && i < (ARRAY_SIZE - 1) ) //find start of number through leading zeros
	{
		i++;
	} //end while
	
	while ( i < ARRAY_SIZE )
	{
		cout << array[ i ];
		i++; //increment counter
	} //end while
	cout << endl;	
} //end function display