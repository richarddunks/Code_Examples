/*	@desc	A test for checking whether an array has no elements.
*
*	@author	Richard Dunks richarddunks@gmail.com
*/
#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

int main()
{
	//variable declaration
	int operand1[ ARRAY_SIZE ] = { 0 };
	int operand2[ ARRAY_SIZE ] = { 0,1,2,3,4,5,6,7,8,9 };
	bool operandFlag;
	
	//function prototype
	bool isZero( int operand[] ); //a function to test for a zero set
	
	//test for zero set in operand1
	operandFlag = isZero( operand1 );
	
	if ( operandFlag == true )
	{
		cout << "Operand1 is a zero array." << endl;
	}
	else
	{
		cout << "Operand 1is not a zero array." << endl;
	} //end if

	
	//test for zero set in operand2
	operandFlag = isZero( operand2 );
	
	if ( operandFlag == true )
	{
		cout << "Operand2 is a zero array." << endl;
	}
	else
	{
		cout << "Operand2 is not a zero array." << endl;
	} //end if	


} //end function main

//begin function definitions
//a function to test for a zero set
bool isZero( int operand[] )
{
	int i = 0; //index counter
	while ( operand[ i ] == 0 && i < ARRAY_SIZE )
	{
		i++;
	} //end while
	if ( i == ARRAY_SIZE )
	{
		return true; //array is a zero array
	}
	else
	{
		return false; //array is not a zero array
	} //end if
} //end function isZero