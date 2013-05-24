/*	@desc	
*
*
*/
#include <iostream>
#include <string>
#include "HugeInteger.h"
using namespace std;

int main()
{
	HugeInteger operand1[ 40 ] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
									1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	HugeInteger operand2[ 40 ] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
									1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
//	HugeInteger result;
	
	
	cout << "The value of operand1 is:\n" << operand1.displayOpr();
	cout << "The value of operand2 is:\n" << operand2.displayOpr();
	
//	result = operand1.addition( operand2 );
	
	
} //end function main