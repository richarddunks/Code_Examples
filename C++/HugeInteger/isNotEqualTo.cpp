/* @desc	A function to test whether two HugeIntegers are not 
*			equal to each other by first testing the size of the 
*			numbers, then comparing each element individually.
*			When the elements are no longer identical, the while
*			loop terminates and the index is tested for being at the 
*			end of the array.  If at the end, the integers are equal
*			If the index is not at the end of the array, the numbers
*			are not equal.
* @pre		An operand is passed to the function to be compared with
*			the data member operand.
* @post		A boolean value is return indicating whether the two
*			integers are not equal (true) or equal (false).
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
	int operand3[ ARRAY_SIZE ] = { 9,8,7,6,5,4,3,2,1,0 };
	bool operandFlag;
//	int opr1Index = 0;
//	int opr2Index = 0;
//	int opr3Index = 0;	

	//function prototype
	bool isNotEqualTo( int opr1[], int opr2[] );

	//test operand1 and operand2
	cout << "For operand1 and operand2: " << endl;
	operandFlag = isNotEqualTo( operand1, operand2 );
	if ( operandFlag == true ) 
	{
		cout << "The operands are not equal." << endl;
	}
	else
	{
		cout << "The operands are equal." << endl;
	} //end if
	//end test

	//test operand1 and operand3
	cout << "For operand1 and operand3: " << endl;
	operandFlag = isNotEqualTo( operand1, operand3 );
	if ( operandFlag == true ) 
	{
		cout << "The operands are not equal." << endl;
	}
	else
	{
		cout << "The operands are equal." << endl;
	} //end if
	//end test

	//test operand2 and operand3
	cout << "For operand2 and operand3: " << endl;
	operandFlag = isNotEqualTo( operand2, operand3 );
	if ( operandFlag == true ) 
	{
		cout << "The operands are not equal." << endl;
	}
	else
	{
		cout << "The operands are equal." << endl;
	} //end if
	//end test



/*
	//find the start of the number
	//while i1 is not at head of operand1 	
	while ( operand1[ opr1Index ] == 0 )
	{
		//operand1 index++;
		opr1Index++;
	} //end while when start of number is found

	//while i2 is not at head of operand2
	while ( operand2[ opr2Index ] == 0 )
	{
		//operand2 index++;
		opr2Index++;
	}//end while

	//while i3 is not at head of operand3
	while ( operand3[ opr3Index ] == 0 )
	{
		//operand3 index++;
		opr3Index++;
	}//end while

	//test for mismatch length implying inequality
	//if i1 != i2
	cout << "For operand1 and operand2: " << endl;
	if ( opr1Index != opr2Index )
	{
		cout << "The operands aren't equal." << endl;
//		return true;
	}
	else
	{
		//compare element to element for equality
		int i = 0; //index counter
		while ( operand1[ i ] == operand2[ i ] && i < ARRAY_SIZE ) 
		//loop until inequality found or reach end of array
		{
			i++;
		} //end while either at point of inequality or end of array
		
		//test for i >= ARRAY_SIZE
		if ( i >= ARRAY_SIZE )
		{
			cout << "The operands are equal." << endl;
//			return false;
		}
		else
		{
			cout << "The operands aren't equal." << endl;
//			return true;
		} //end if
	} //end if

	cout << "For operand1 and operand3: " << endl;
	if ( opr1Index != opr3Index )
	{
		cout << "The operands aren't equal." << endl;
//		return true;
	}
	else
	{
		//compare element to element for equality
		int i = 0; //index counter
		while ( operand1[ i ] == operand3[ i ] && i < ARRAY_SIZE ) 
		//loop until inequality found or reach end of array
		{
			i++;
		} //end while either at point of inequality or end of array
		
		//test for i >= ARRAY_SIZE
		if ( i >= ARRAY_SIZE )
		{
			cout << "The operands are equal." << endl;
//			return false;
		}
		else
		{
			cout << "The operands aren't equal." << endl;
//			return true;
		} //end if
	} //end if

	cout << "For operand2 and operand3: " << endl;
	if ( opr2Index != opr3Index )
	{
		cout << "The operands aren't equal." << endl;
//		return true;
	}
	else
	{
		//compare element to element for equality
		int i = 0; //index counter
		while ( operand2[ i ] == operand3[ i ] && i < ARRAY_SIZE ) 
		//loop until inequality found or reach end of array
		{
			i++;
		} //end while either at point of inequality or end of array
		
		//test for i >= ARRAY_SIZE
		if ( i >= ARRAY_SIZE )
		{
			cout << "The operands are equal." << endl;
//			return false;
		}
		else
		{
			cout << "The operands aren't equal." << endl;
//			return true;
		} //end if
	} //end if
*/

} //end function main

//begin function definition
bool isNotEqualTo( int opr1[], int opr2[] )
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
	//if i1 != i2
	if ( opr1Index != opr2Index )
	{
		return true;
	}
	else
	{
		//compare element to element for equality
		int i = 0; //index counter
		while ( opr1[ i ] == opr2[ i ] && i < ARRAY_SIZE ) 
		//loop until inequality found or reach end of array
		{
			i++;
		} //end while either at point of inequality or end of array
		
		//test for i >= ARRAY_SIZE
		if ( i >= ARRAY_SIZE )
		{
			return false;
		}
		else
		{
			return true;
		} //end if
	} //end if

	
} //end function isNotEqualTo