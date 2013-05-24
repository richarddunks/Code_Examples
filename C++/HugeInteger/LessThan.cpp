/* @desc	A boolean function to test whether two HugeIntegers are 
*			less than or equal to each other by first testing the 
*			size of the numbers, then comparing each element individually
*			if the lengths are equal.  A while loop starts at the most
*			significant digit until an inequality is found or the end of
*			the array is reached, at which point, the loop terminates
*			and the significant digits are tested to determine which 
*			integer is less.
* @pre		An operand is passed to the function to be compared with
*			the data member operand.
* @post		A boolean value is return indicating whether opr is less
*			than or equal to the passed operand (true) or not (false).
* @author	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

int main()
{
	//variable declaration
	int operand1[ ARRAY_SIZE ] = { 0,1,2,3,4,5,6,7,8,9 }; 
	int operand2[ ARRAY_SIZE ] = { 0,1,2,3,4,5,6,7,8,9 };
	int operand3[ ARRAY_SIZE ] = { 0,0,2,3,4,5,6,7,8,9 };
	bool operandFlag;

	//function prototype
	bool isLessThanOrEqualTo( int opr1[], int opr2[] );
	void output( int opr[] );
	
	//test operand1 and operand2
	cout << "For operand1 ";
	output( operand1 ); 
	cout << " and operand2 ";
	output( operand2 );
	
	operandFlag = isLessThanOrEqualTo( operand1, operand2 );
	if ( operandFlag == true ) 
	{
		cout << "The first operand is less than or equal to the second." << endl;
	}
	else
	{
		cout << "The first operand is not less than or equal to the second." << endl;
	} //end if
	//end test

	//test operand1 and operand2
	cout << "For operand2 ";
	output( operand2 ); 
	cout << " and operand1 ";
	output( operand1 );
	
	operandFlag = isLessThanOrEqualTo( operand2, operand1 );
	if ( operandFlag == true ) 
	{
		cout << "The first operand is less than or equal to the second." << endl;
	}
	else
	{
		cout << "The first operand is not less than or equal to the second." << endl;
	} //end if
	//end test


	//test operand1 and operand3
	cout << "For operand1 ";
	output( operand1 ); 
	cout << " and operand3 ";
	output( operand3 );
	
	operandFlag = isLessThanOrEqualTo( operand1, operand3 );
	if ( operandFlag == true ) 
	{
		cout << "The first operand is less than or equal to the second." << endl;
	}
	else
	{
		cout << "The first operand is not less than or equal to the second." << endl;
	} //end if
	//end test

	//test operand3 and operand1
	cout << "For operand3 ";
	output( operand3 ); 
	cout << " and operand1 ";
	output( operand1 );
	
	operandFlag = isLessThanOrEqualTo( operand3, operand1 );
	if ( operandFlag == true ) 
	{
		cout << "The first operand is less than or equal to the second." << endl;
	}
	else
	{
		cout << "The first operand is not less than or equal to the second." << endl;
	} //end if
	//end test


	//test operand2 and operand3
	cout << "For operand2 ";
	output( operand2 ); 
	cout << " and operand3 ";
	output( operand3 );
	
	operandFlag = isLessThanOrEqualTo( operand2, operand3 );
	if ( operandFlag == true ) 
	{
		cout << "The first operand is less than or equal to the second." << endl;
	}
	else
	{
		cout << "The first operand is not less than or equal to the second." << endl;
	} //end if
	//end test

	//test operand3 and operand2
	cout << " and operand3 ";
	output( operand3 );
	cout << "For operand2 ";
	output( operand2 ); 
	
	operandFlag = isLessThanOrEqualTo( operand3, operand2 );
	if ( operandFlag == true ) 
	{
		cout << "The first operand is less than or equal to the second." << endl;
	}
	else
	{
		cout << "The first operand is not less than or equal to the second." << endl;
	} //end if
	//end test


} //end function main

//begin function definition
//function prototype
bool isLessThanOrEqualTo( int opr1[], int opr2[] )
{
	int opr1Index = 0;
	int opr2Index = 0;

	//find the start of the operands
	//while i1 is not at head of operand1 	
	while ( opr1[ opr1Index ] == 0 )
	{
		opr1Index++;
	} //end while when start of number is found

	//while i2 is not at head of operand2
	while ( opr2[ opr2Index ] == 0 )
	{
		opr2Index++;
	}//end while
	
	//test for mismatch length implying inequality
	if ( opr1Index > opr2Index )
	{
		return true; //opr1 is a smaller number than opr2
	}
	else if ( opr1Index < opr2Index )
	{
		return false; //opr1 is a larger number than opr2
	}
	else //enter when the length of opr1 and opr2 are the same
	{
		//compare element to element for equality (opr1Index == opr1Index)
		int i = 0; //index counter set to start of number
		while ( opr1[ i ] == opr2[ i ] && i < ARRAY_SIZE ) 
		//loop digits starting at most significant to find inequality to test
		{
			i++;
		} //end while at point of inequality or end of array
		
		//test for i >= ARRAY_SIZE
		if ( opr1[ i ] < opr2[ i ] || i >= ARRAY_SIZE )
		{
			return true; //opr1 < opr2
		}
		else
		{
			return false; //opr1 > opr2
		} //end if
	} //end if
} //end function isLessThanOrEqualTo

void output( int opr[] )
{
	int i = 0;
	
	while ( opr[ i ] == 0 ) //find start of number through leading zeros
	{
		i++;
	} //end while
	
	while ( i < ARRAY_SIZE )
	{
		cout << opr[ i ];
		i++; //increment counter
	} //end while
	cout << endl;	
} //end function output


//end function definitions
