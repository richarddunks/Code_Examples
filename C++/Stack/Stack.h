



/* @title	CISC2200 Stack Class: Stack.h
*  @desc	A templated Stack class for use with infix and postfix 
*			expression evaluation.
*  @auth	Richard Dunks richarddunks@gmail.com 
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template< typename T >

class Stack
{
public:
	Stack(); //default constructor
	~Stack(); //destructor
	bool isEmpty() const; //check for empty stack
	void push( const T &newItem ); //push nodes to the stack
	void pop(); //pop Nodes from the stack without saving content
	void pop( T &stackTop ); //pop Nodes from the stack and return content
	void getTop( T &stackTop ) const; //get value in top without deleting
	void displayStack();
private:
	struct Node
	{
		T item; //data type in node
		Node *next; //pointer to next item in stack
	}; //end struct Node

	Node *top; //pointer to top Node in stack
}; //end class Stack

//begin function definition

template< typename T >
Stack<T>::Stack() //default constructor
{
	top = NULL;
} //end default constructor

template< typename T >
Stack<T>::~Stack() //destructor
{
	while ( !isEmpty() )
	{
		pop(); //delete all elements in the stack
	} //end while
} //end destructor

template< typename T >
bool Stack<T>::isEmpty() const //check for empty stack
{
	if ( top == NULL ) 
		return true;
	else
		return false;
} //end function isEmpty

template< typename T >
void Stack<T>::push( const T &newItem ) //push nodes to the stack
{
	//instantiate new Node
	Node *newNode = new Node;
	
	//fill with data
	newNode -> item = newItem;
	
	//push Node to top of stack
	newNode -> next = top;

	//change top of stack to new Node
	top = newNode;
	
} //end function push

template< typename T >
void Stack<T>::pop() //pop Nodes from the stack without saving content
{
	if ( isEmpty() )
	{
		cerr << "The stack is empty" << endl;
	}
	else //stack is not empty
	{
		//create temporary Node
		Node *tempNode = top;
		//advance top to the next element
		top = top -> next;
		//set temp Node to NULL
		tempNode -> next = NULL;
		//delete tempNode
		delete tempNode;
	} //end if
} //end function pop

template< typename T >
void Stack<T>::pop( T &stackTop ) //pop Nodes from the stack
{
	if ( isEmpty() )
	{
		cerr << "The stack is empty" << endl;
	}
	else //stack is not empty
	{
		//retrieve element and pass into object
		stackTop = top -> item;
		
		//create temporary Node
		Node *tempNode = top;
		//advance top to the next element
		top = top -> next;
		//set temp Node to NULL
		tempNode -> next = NULL;
		//delete tempNode
		delete tempNode;
	}	
} //end function pop

template< typename T >
void Stack<T>::getTop( T &stackTop ) const //get value in top without deleting
{
	if ( isEmpty() )
	{
//		cerr << "The stack is empty" << endl;
	}
	else
	{
		stackTop = top -> item;
	} //end if

} //end function getTop

template< typename T >
void Stack<T>::displayStack()
{
	T output;
	
	cout << "The contents of the Stack were:";
	while ( !isEmpty() )
	{
		pop( output );
		cout << output;	
	}

	cout << endl;
	cout << "The Stack is now empty" << endl;
}

#endif





