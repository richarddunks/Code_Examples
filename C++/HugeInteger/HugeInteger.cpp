

/*	@desc	A class to calculate integers up to 40 digits long
*	@pre	An integer array of length 40. 
*	@post	Integer array of length 40 as the result of the function
*			operator either addition or multiplication, as well as boolean
*			values from logic operations.
*	@author	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include <string>
#include "HugeInteger.h"
using namespace std;

//default constructor
HugeInteger::HugeInteger()
{
	for ( int i = 0; i < ARRAY_SIZE; i++ )
	{
		opr[ i ] = 0; //initialize opr to 0
	} //end for
} //end default constructor

//constructor with integer array
HugeInteger::HugeInteger( int operand[] )
{
	for ( int i = 0; i < ARRAY_SIZE; i++ )
	{
		opr[ i ] = operand[ i ]; //assign passed array to data member
	} //end for
} //end constructor

//input operand to array
void HugeInteger::input( int operand[] )
{
	for ( int i = 0; i < ARRAY_SIZE; i++ )
	{
		opr[ i ] = operand[ i ]; //assign passed array to data member
	} //end for
} //end function input

//a function to add operands
HugeInteger HugeInteger::addition( HugeInteger opr2 )
{
	int carryover[ ARRAY_SIZE ] = { 0 }; //array to catch the carryover from addition
	HugeInteger sum; //instantiate HugeInteger sum object to hold sum
	
	for ( int i = ARRAY_SIZE - 1; i >= 0; i-- )
	{
		int j = i - 1 ; //advance counter to set the carryover in the next addition line
		int result = opr[ i ] + opr2.opr[ i ] + carryover[ i ];
		carryover[ j ] = result / 10;
		sum.opr[ i ] = result % 10;
	} //end for
	return sum;
} //end function addition


/* @desc	A function to multiply the elements of two integer arrays with
*			each other. The first for loop (i-controlled) loops through operand2
*			while the second for loop (j-controlled) loops through operand1.
*			k, initialized in the beginning of the i-controlled for loop,  
*			controls the placement of the multiplication result in the proper
*			place of the product array, which shifts with each iteration through
*			the j-controlled loop. The resulting product array contains two-digit
*			integers (overflow) that are "cleaned up" in the second for loop
*			(k-controlled) in order to create the proper result.
* @pre		The HugeInteger object is passed to be multiplied to the data member.
* @post		The product HugeInteger object contains the result of the 
*			multiplication operation.
* @author	Richard Dunks richarddunks@gmail.com
*/
HugeInteger HugeInteger::multiplication( HugeInteger opr2 ) //multiply HugeInts
{
	HugeInteger product; //HugeInteger object to hold the product of operands

	for ( int i = ARRAY_SIZE - 1; i >= 0; i--) //loop through opr2
	{
		int k = i; //index value for product array
		int carryover[ ARRAY_SIZE ] = { 0 }; //reinitialize carryover array each pass

		//inner j-controlled loop through data member opr
		for ( int j = ARRAY_SIZE - 1; j >= 0; j--) 
		{
			int result = ( opr[ j ] * opr2.opr[ i ] ) + carryover[ j ]; //raw calculation
			product.opr[ k ] += result % 10; //ones digit of multiplication result
			carryover[ (j - 1) ] = result / 10; //assignment of value to carryover array
			k--;
		} //end for loop through data member opr
	} //end for loop through opr2

	//clean up overflow in product array
	int carryover[ ARRAY_SIZE ] = { 0 }; //carryover array for addition
	for ( int k = ARRAY_SIZE - 1; k >= 0; k--)
	{
		if ( product.opr[ k ] > 9 || carryover[ k ] != 0 ) //test for product array value >9 or carryover value
		{	
			int result = product.opr[ k ] + carryover [ k ];

			product.opr[ k ] = result % 10;			
			carryover[ (k - 1) ] = result / 10; //assignment of value to carryover array
		} //end if
	} //end for loop to clean up product overflow
	return product;
} //end function multiplication


//a function to test for a zero set
bool HugeInteger::isZero()
{
	int i = 0; //index counter
	while ( opr[ i ] == 0 && i < ARRAY_SIZE )
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

//function to test for two operands being equal
bool HugeInteger::isEqualTo( HugeInteger opr2 )
{
	int i = 0; //index counter
	
	while ( opr[ i ] == opr2.opr[ i ] ) //compare operands sequentially
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

//test for integers being unequal
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
bool HugeInteger::isNotEqualTo( HugeInteger opr2 ) 
{
	int oprIndex = 0;
	int opr2Index = 0;
	
	//find the start of the operands
	//while i1 is not at head of operand1 	
	while ( opr[ oprIndex ] == 0 )
	{
		oprIndex++;
	} //end while when start of number is found

	//while i2 is not at head of operand2
	while ( opr2.opr[ opr2Index ] == 0 )
	{
		opr2Index++;
	}//end while

	//test for mismatch length implying inequality
	if ( oprIndex != opr2Index )
	{
		return true;
	}
	else
	{
		//compare element to element for equality
		int i = 0; //index counter
		while ( opr[ i ] == opr2.opr[ i ] && i < ARRAY_SIZE ) 
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

/* @desc	A boolean function to test whether two HugeIntegers are 
*			equal to or greater than each other by first testing the 
*			size of the numbers, then comparing each element individually
*			if the lengths are equal.  A while loop starts at the most
*			significant digit until an inequality is found or the end of
*			the array is reached, at which point, the loop terminates
*			and the significant digits are tested to determine which 
*			integer is greater.
* @pre		An operand is passed to the function to be compared with
*			the data member operand.
* @post		A boolean value is return indicating whether opr is greater
*			than or equal to the passed operand (true) or not (false).
* @author	Richard Dunks richarddunks@gmail.com
*/
bool HugeInteger::isGreaterThanOrEqualTo( HugeInteger opr2 )
{
	int oprIndex = 0;
	int opr2Index = 0;

	//find the start of the operands
	//while i1 is not at head of operand1 	
	while ( opr[ oprIndex ] == 0 )
	{
		oprIndex++;
	} //end while when start of number is found

	//while i2 is not at head of operand2
	while ( opr2.opr[ opr2Index ] == 0 )
	{
		opr2Index++;
	}//end while
	
	//test for mismatch length implying inequality
	if ( oprIndex < opr2Index )
	{
		return true; //opr is a larger number than opr2
	}
	else if ( oprIndex > opr2Index )
	{
		return false; //opr is a smaller number than opr2
	}
	else //enter when the length of opr and opr2 are the same
	{
		//compare element to element for equality (oprIndex == oprIndex)
		int i = 0; //index counter set to start of number
		while ( opr[ i ] == opr2.opr[ i ] && i < ARRAY_SIZE ) 
		//loop digits starting at most significant to find inequality to test
		{
			i++;
		} //end while at point of inequality or end of array
		
		//test for i >= ARRAY_SIZE
		if ( opr[ i ] > opr2.opr[ i ] || i >= ARRAY_SIZE )
		{
			return true; //opr >= opr2
		}
		else
		{
			return false; //opr < opr2
		} //end if
	} //end if
} //end function isGreaterThanOrEqualTo


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
bool HugeInteger::isLessThanOrEqualTo( HugeInteger opr2 )
{
	int oprIndex = 0;
	int opr2Index = 0;

	//find the start of the operands
	//while i1 is not at head of operand1 	
	while ( opr[ oprIndex ] == 0 )
	{
		oprIndex++;
	} //end while when start of number is found

	//while i2 is not at head of operand2
	while ( opr2.opr[ opr2Index ] == 0 )
	{
		opr2Index++;
	}//end while
	
	//test for mismatch length implying inequality
	if ( oprIndex > opr2Index )
	{
		return true; //opr is a smaller number than opr2
	}
	else if ( oprIndex < opr2Index )
	{
		return false; //opr is a larger number than opr2
	}
	else //enter when the length of opr and opr2 are the same
	{
		//compare element to element for equality (oprIndex == oprIndex)
		int i = 0; //index counter set to start of number
		while ( opr[ i ] == opr2.opr[ i ] && i < ARRAY_SIZE ) 
		//loop digits starting at most significant to find inequality to test
		{
			i++;
		} //end while at point of inequality or end of array
		
		//test for i >= ARRAY_SIZE
		if ( opr[ i ] < opr2.opr[ i ] || i >= ARRAY_SIZE )
		{
			return true; //opr < opr2
		}
		else
		{
			return false; //opr > opr2
		} //end if
	} //end if
} //end function isLessThanOrEqualTo


//function to display integer array
void HugeInteger::output()
{
	int i = 0;
	
	while ( opr[ i ] == 0 && i < (ARRAY_SIZE - 1) ) 
	//loop to start of number with second condition to ensure last digit is displayed
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




