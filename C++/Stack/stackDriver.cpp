


/* @title	CISC2200 Stack Class: stackDriver.cpp
*  @desc	A driver program to implement and test the templated Stack
*			class to convert an infix expression to a postfix expression
*			and evaluate the postfix expression.
*  @auth	Richard Dunks richarddunks@gmail.com 
*/


#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

static const int EXP_LEN = 20;

int main() 
{
	//variable declaration
	Stack< char > operatorStack; //Stack for operators from infix expression
	Stack< int > operandStack; //Stack for operands from postfix expression
	char inFix[ EXP_LEN ]; //infix expression character array
	string postFix; //postfix expression string
	bool inputComplete = false;

	//begin program operation
	while ( inputComplete == false )
	{
		//input infix expression	
		cout << "Infix Expression? (enter - to exit): ";
		cin.getline( inFix, EXP_LEN );
		
		if ( inFix[ 0 ] != '-' )
		{
			//break out operators and operands
			for ( int i = 0; inFix[ i ] != '\0'; i++ )
			{
				char ch = inFix[ i ]; //evaluate the character array one element at a time
				switch (ch)
				{
					//operand cases:
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						postFix += ch;
						break;

					//operator cases
					case '(':
						operatorStack.push( ch );
						break;
					case ')':
						char stackTop; //char to get the stackTop
						operatorStack.getTop( stackTop ); //fill stackTop with top of stack
				
						while ( stackTop != '(' ) //test for (
						{
							operatorStack.pop( stackTop ); //pop operators off stack
							postFix += stackTop; //append operator to postFix string
							operatorStack.getTop( stackTop ); //advance stackTop to next operator
						} //end while
				
						operatorStack.pop(); //pop off the (
						break;

					case '+':
					case '-':
						if (!operatorStack.isEmpty() )
						{
							char stackTop;
							operatorStack.getTop( stackTop );
				
							while ( !operatorStack.isEmpty() && stackTop != '(' )
							{
								operatorStack.pop( stackTop ); //pop operators off stack
								postFix += stackTop; //append operator to postFix string					
								operatorStack.getTop( stackTop ); //advance stackTop for next test
							} //end while
						} //end if
						operatorStack.push( ch );				
						break;
				
					case '*':
					case '/':
						if (!operatorStack.isEmpty() )
						{
							char stackTop;
							operatorStack.getTop( stackTop );

							while ( !operatorStack.isEmpty() && stackTop != '(' && stackTop != '+' && stackTop != '-' )
							{
								operatorStack.pop( stackTop ); //pop operators off stack
								postFix += stackTop; //append operator to postFix string					
								operatorStack.getTop( stackTop ); //advance stackTop for next test
							} //end while
						} //end if					
						operatorStack.push( ch );
						break;
						
				} //end switch	
			} //end for
	
			while ( !operatorStack.isEmpty() )
			{	
				char stackTop;
				operatorStack.pop( stackTop );
				postFix += stackTop; //append operator to postFix string
			} //end while

/*
			cout << "Displaying the postFix string..." << endl;
			cout << postFix << endl;
*/

			//evaluate postfix expression
			//convert string to character array
			char const *postFixChar = postFix.c_str();

			//while current character is not NULL
			for ( int i = 0; postFixChar[ i ] != '\0'; i++ )
			{
				char ch = postFixChar[ i ];
				switch ( ch )
				{
					//operand cases:
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					{
						int chInt = ch - '0';
						operandStack.push( chInt );
						break;
					}
			
					//operator cases
					case '+':
					{
						int op1, op2, result;
						operandStack.pop( op2 );
						operandStack.pop( op1 );
						result = op1 + op2;
						operandStack.push( result );
						break;
					}
					case '-':
					{
						int op1, op2, result;
						operandStack.pop( op2 );
						operandStack.pop( op1 );
						result = op1 - op2;
						operandStack.push( result );
						break;
					}
					case '*':
					{
						int op1, op2, result;
						operandStack.pop( op2 );
						operandStack.pop( op1 );
						result = op1 * op2;
						operandStack.push( result );
						break;
					}
					case '/':
					{
						int op1, op2, result;
						operandStack.pop( op2 );
						operandStack.pop( op1 );
						result = op1 / op2;
						operandStack.push( result );
						break;
					}
				} //end switch
			} //end for		

			int result;
			operandStack.pop( result );
			cout << result << endl;
		}
		else
		{
			inputComplete = true;
		}
	} //end while and program exit

} //end function main






