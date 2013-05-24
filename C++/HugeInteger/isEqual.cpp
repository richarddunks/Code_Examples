/*	@desc	A test for checking whether two integer arrays
*			are equal.
*	@author	Richard Dunks richarddunks@gmail.com
*/
#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

int main()
{
	//variable declaration
	int operand1[ ARRAY_SIZE ] = { 0,1,2,3,4,5,6,7,8,9 }; 
	int operand2[ ARRAY_SIZE ] = { 0,1,2,3,4,5,6,7,8,9 };
	int operand3[ ARRAY_SIZE ] = { 9,8,7,6,5,4,3,2,1,0 };
	bool operandFlag;

	//function prototype
	bool isEqual( int opr1[], int opr2[] );
	
	
	//compare operand1 and operand2
	operandFlag = isEqual( operand1, operand2 );

	//test boolean flag
	if ( operandFlag == true ) //test for positive case
	{
		cout << "Operand1 and Operand2 are equivalent." << endl;
	}
	else //negative clase
	{
		cout << "Operand1 and Operand2 are not equivalent." << endl;
	} //end if

	
	//compare operand2 and operand3
	operandFlag = isEqual( operand2, operand3 );
	if ( operandFlag == true ) //test for positive case
	{
		cout << "Operand2 and Operand3 are equivalent." << endl;
	}
	else //negative clase
	{
		cout << "Operand2 and Operand3 are not equivalent." << endl;
	} //end if

	
} //end function main

//begin function definitions
//compare two operands
bool isEqual( int opr1[], int opr2[] )
{
	int i = 0; //index counter
	
	while ( opr1[ i ] == opr2[ i ] ) //compare operands sequentially
	{
		i++;
	} //end while when either reach end of array or mismatch between elements
	if ( i >= ARRAY_SIZE ) //test for positive case
	{
		return true;
	}
	else //negative clase
	{
		return false;
	} //end if
} //end function isEqual