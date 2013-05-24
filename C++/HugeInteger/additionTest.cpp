/*	Test of HugeInteger addition
*/
#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

int main()
{
	//variable declaration
	int operand1[ ARRAY_SIZE ] = { 0,5,5,5,5,5,5,5,5,5 };
	int operand2[ ARRAY_SIZE ] = { 0,5,5,5,5,5,5,5,5,5 };
//	int carryover[ ARRAY_SIZE ] = { 0 }; //carryover array from addition operation
	int sum[ ARRAY_SIZE ] = { 0 }; //sum array for operand 1 + operand 2
//	int result; //result from addition of each array element
//	int onesResult; //ones digit from the addition operation
//	int tensResult; //tens digit from the addition operation


	//function prototypes
	void addition( int opr1[], int opr2[], int sum[] ); //function to add operands
	void display( int array[] ); //display array
	
	cout << "Operand1 = ";
	display( operand1 );
	cout << "Operand2 = ";
	display( operand2 );
	cout << "Sum = ";
	display( sum );

	addition( operand1, operand2, sum );

/*	
	for ( int i = ARRAY_SIZE - 1; i >= 0; i-- )
	{
		int j = i - 1 ;
		result = operand1[ i ] + operand2[ i ] + carryover[ i ];
		carryover[ j ] = result / 10;
		sum[ i ] = result % 10;

	} //end for
*/
	cout << "Operand1 = ";
	display( operand1 );
	cout << "Operand2 = ";
	display( operand2 );
	cout << "Sum = ";
	display( sum );

} //end function main


//begin function definitions
void addition( int opr1[], int opr2[], int sum[] ) //function to add operands
{
	int carryover[ ARRAY_SIZE ] = { 0 }; //array to catch the carryover from addition
	
	for ( int i = ARRAY_SIZE - 1; i >= 0; i-- )
	{
		int j = i - 1 ; //advance counter to set the carryover in the next addition line
		int result = opr1[ i ] + opr2[ i ] + carryover[ i ];
		carryover[ j ] = result / 10;
		sum[ i ] = result % 10;

	} //end for
} //end function addition


void display( int array[] ) //display array
{
	for ( int i = 0; i < ARRAY_SIZE; i++ )
	{
		cout << array[ i ];
	} //end for
	cout << endl;	
} //end function display