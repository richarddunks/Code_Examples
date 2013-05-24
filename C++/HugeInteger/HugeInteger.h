


/*	@desc	A class to calculate integers up to 40 digits long
*	@pre	An integer array of length 40. 
*	@post	Integer array of length 40 as the result of the function
*			operator either addition or multiplication, as well as boolean
*			values from logic operations.
*	@author	Richard Dunks richarddunks@gmail.com
*/

#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <iostream>
using namespace std;

static const int ARRAY_SIZE = 40;

class HugeInteger
{
public:
	HugeInteger(); //default constructor
	HugeInteger ( int operand[] ); //constructor with value
	void input( int operand[] ); //input operand to array
	HugeInteger addition( HugeInteger opr2 ); //function to add operands
	HugeInteger multiplication( HugeInteger opr2 ); //function to multiply operands
	bool isZero(); //test for a zero set
	bool isEqualTo( HugeInteger opr2 ); //test for opr and opr2 being equal
	bool isNotEqualTo( HugeInteger opr2 ); //test for opr and opr2 not being equal
	bool isGreaterThanOrEqualTo( HugeInteger opr2 ); //test for opr >= opr2
	bool isLessThanOrEqualTo( HugeInteger opr2 );	//test for opr <= opr2
	void output();
private:
	int opr[ ARRAY_SIZE ]; //integer array holding the huge integer
}; //end class HugeInteger

#endif


