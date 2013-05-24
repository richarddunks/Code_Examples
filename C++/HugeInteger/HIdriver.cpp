/* @desc	A driver test program for HugeInteger Class.
*  @author	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include <string>
#include "HugeInteger.h"
using namespace std;

int main()
{
	//begin variable declarations
	int opr1[ ARRAY_SIZE ] = { 0,1,2,3,4,5,6,7,8,9 }; 
	int opr2[ ARRAY_SIZE ] = { 0,1,2,3,4,5,6,7,8,9 };
	int opr3[ ARRAY_SIZE ] = { 0,0,2,3,4,5,6,7,8,9 };
	int opr4[ ARRAY_SIZE ] = { 0,0,0,0,0,0,6,7,8,9 };
	int opr5[ ARRAY_SIZE ] = { 0,0,0,0,0,0,1,2,3,4 };
	int opr6[ ARRAY_SIZE ] = { 0 };
	HugeInteger operand1 = opr1;
	HugeInteger operand2 = opr2;
	HugeInteger operand3 = opr3;
	HugeInteger operand4 = opr4;
	HugeInteger operand5 = opr5;
	HugeInteger operand6 = opr6;
	bool operandFlag;
	//end variable declarations
	
	//function prototypes
	void boolTest( bool oprFlag );

	//test output function
	cout << "The value of operand1 is: ";
	operand1.output();
	cout << "The value of operand2 is: ";
	operand2.output();
	cout << "The value of operand3 is: ";
	operand3.output();	
	cout << "The value of operand4 is: ";
	operand4.output();	
	cout << "The value of operand5 is: ";
	operand5.output();
	cout << "The value of operand6 is: ";
	operand6.output();	

	//test addition operation
	cout << "The sum of operand1 and operand2 is: " << endl;
	HugeInteger sum = operand1.addition( operand2 );
	sum.output();

	//test multiplication operation
	cout<< "The product of operand4 and operand5 is: "<< endl;
	HugeInteger product = operand4.multiplication( operand5 );
	product.output();

	cout<< "The product of operand5 and operand6 is: "<< endl;
	product = operand5.multiplication( operand6 );
	product.output();


	//test isZero
	cout << "Test isZero on operand5 ";
	operandFlag = operand5.isZero();
	boolTest( operandFlag );

	cout << "Test isZero on operand6 ";
	operandFlag = operand6.isZero();
	boolTest( operandFlag );
	
	//test isEqual
	cout << "Test isEqual on operand1 and operand2 ";
	operandFlag = operand1.isEqual( operand2 );
	boolTest( operandFlag );

	cout << "Test isEqual on operand3 and operand4 ";
	operandFlag = operand3.isEqual( operand4 );
	boolTest( operandFlag );
	
	//test isNotEqualTo
	cout << "Test isNotEqualTo on operand1 and operand2";
	operandFlag = operand1.isNotEqualTo( operand2 );
	boolTest( operandFlag );

	cout << "Test isNotEqualTo on operand3 and operand4";
	operandFlag = operand3.isNotEqualTo( operand4 );
	boolTest( operandFlag );
	
	//test isGreaterThanOrEqualTo
	cout << "Test isGreaterThanOrEqualTo on operand1 and operand2 ";
	operandFlag = operand1.isGreaterThanOrEqualTo( operand2 );
	boolTest( operandFlag );

	cout << "Test isGreaterThanOrEqualTo on operand2 and operand1 ";
	operandFlag = operand2.isGreaterThanOrEqualTo( operand1 );
	boolTest( operandFlag );

	cout << "Test isGreaterThanOrEqualTo on operand3 and operand4 ";
	operandFlag = operand3.isGreaterThanOrEqualTo( operand4 );
	boolTest( operandFlag );

	cout << "Test isGreaterThanOrEqualTo on operand4 and operand3 ";
	operandFlag = operand4.isGreaterThanOrEqualTo( operand3 );
	boolTest( operandFlag );
	
	//test isLessThanOrEqualTo
	cout << "Test isLessThanOrEqualTo on operand1 and operand2 ";
	operandFlag = operand1.isLessThanOrEqualTo( operand2 );
	boolTest( operandFlag );

	cout << "Test isLessThanOrEqualTo on operand2 and operand1 ";
	operandFlag = operand2.isLessThanOrEqualTo( operand1 );
	boolTest( operandFlag );

	cout << "Test isLessThanOrEqualTo on operand5 and operand6 ";
	operandFlag = operand5.isLessThanOrEqualTo( operand6 );
	boolTest( operandFlag );

	cout << "Test isLessThanOrEqualTo on operand6 and operand5 ";
	operandFlag = operand6.isLessThanOrEqualTo( operand5 );
	boolTest( operandFlag );
	


} //end function main

//begin function declarations
void boolTest( bool oprFlag ) //output results of boolean test
{
	if ( oprFlag == true )
	{
		cout << "The value is true." << endl;
	}
	else
	{
		cout << "The value is false." << endl;	
	}
}
//end function declarations