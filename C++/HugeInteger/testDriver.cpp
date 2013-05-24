

/* @desc	A driver program to demonstrate the functionality of the HugeInteger Class
*  @pre		None.
*  @post	The output of the equation as entered by the user.
*  @author	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "HugeInteger.h"
using namespace std;

int main()
{
	//variable declarations
	string entry; //user entered equation
	string continueFlag = "Y"; //sentinel value for while loop
	int entryLength; //length of string entered by user
	int space1; //location of first space
	int space2; //location of second space
	string userOperator; //operator used in the equation
	string operand1String; //substring of entry with operand1
	string operand2String; //substring of entry with operand2
	bool oprFlag; //boolean value for logic test
	
	//function prototypes
	void output( int opr[] ); //output array function
	void parseString( string oprString, int oprArray[] ); //parse string to int
	void boolTest( bool oprFlag ); //check boolean string and output result
	
	while ( continueFlag == "Y" || continueFlag == "y" )
	{
		int operand1Array[ ARRAY_SIZE ] = { 0 }; //int array of operand1
		int operand2Array[ ARRAY_SIZE ] = { 0 }; //int array of operand2
	
		//prompt user for input
		cout << "Enter an equation: ";

		//getline to receive input
		getline( cin, entry );

		//getlength of string input
		entryLength = entry.length();

		//find position of space1, starting at beginning
		space1 = entry.find( " " );

		//find position of space2, starting at space1 + 1
		space2 = entry.find( " ", space1 + 1 );

		//determine operator and store (between space1 and space2)
		userOperator = entry.substr( space1 + 1, (space2 - (space1 + 1)) );

		//substring from beginning to space1 - 1 for first HugeInteger
		operand1String = entry.substr( 0, space1 );

		//parse operand1String to operand1Array
		parseString( operand1String, operand1Array );

		//instantiate HugeInteger object and assign array
		HugeInteger opr1 = operand1Array;

		//substring from space2 to end of input for second HugeInteger
		operand2String = entry.substr( space2 + 1, entryLength - (space2 + 1) );

		//parse operand2String to operand2Array
		parseString( operand2String, operand2Array );
		
		//instantiate HugeInteger object
		HugeInteger opr2 = operand2Array;

		//test operator
		if ( userOperator == "+" )
		{
			HugeInteger sum = opr1.addition( opr2 );
			sum.output();
		} //end addition test
		else if ( userOperator == "*" )
		{
			HugeInteger product = opr1.multiplication( opr2 );
			product.output();
		} //end multiplication test
		else if ( userOperator == "<=" )
		{
			oprFlag = opr1.isLessThanOrEqualTo( opr2 );
			boolTest( oprFlag );
		} //end isLessThanOrEqualTo test
		else if ( userOperator == ">=" )
		{
			oprFlag = opr1.isGreaterThanOrEqualTo( opr2 );
			boolTest( oprFlag );
		} //end isGreaterThanOrEqualTo test
		else if ( userOperator == "==" )
		{
			oprFlag = opr1.isEqualTo( opr2 );
			boolTest( oprFlag );
		} //end isEqualTo test
		else if ( userOperator == "!=" )
		{
			oprFlag = opr1.isNotEqualTo( opr2 );
			boolTest( oprFlag );
		} //end isNotEqualTo test
		else
		{
			cout << "Unrecognized operator." << endl;
		} //end if operator test

		//prompt for another equation
		cout << "Enter another equation (Y or N)?: ";
		getline( cin, continueFlag );
	} //end program while
	cout << "Thank you for using the HugeInteger Class!" << endl;
	cout << endl;
	
} //end function main

//begin function definitions

/* @desc	A function to take a user-inputted string of integers and convert it 
*			to an array of integers by taking each element of the string, converting
*			it to a character array of size 1, and then using the atoi function to 
*			convert it to an integer and assigning it to the integer array.
*  @pre		A string of integers and the integer array.
*  @post	The integer array, passed by reference is populated with the converted
*			integers.
*  @author	Richard Dunks richarddunks@gmail.com
*/
void parseString( string oprString, int oprArray[] )
{
	//loop to parse operand1 string into integer array starting with least sig digit
	//variable i indexes the operand while variable j indexes the int array
	int oprLength = oprString.length();
	for ( int i = (oprLength - 1), j = (ARRAY_SIZE - 1); i >= 0; i--, j-- )
	{
		string entrySub = oprString.substr( i, 1 ); //substring char by char		
		const char *oprCharArray = entrySub.c_str(); //convert substring to character array	
		oprArray[ j ] = atoi( oprCharArray ); //convert substring to int and assign
	} //end for
} //end function parseString

void boolTest( bool oprFlag ) //output results of boolean test
{
	if ( oprFlag == true )
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;	
	}
} //end function boolTest
//end function declarations




