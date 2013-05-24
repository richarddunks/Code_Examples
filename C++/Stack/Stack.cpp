//Stack.cpp

#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() //default constructor
{
	top = NULL;
} //end default constructor

Stack::~Stack() //destructor
{
	while ( !isEmpty() )
	{
		pop(); //delete all elements in the stack
	} //end while
} //end destructor

bool Stack::isEmpty() const //check for empty stack
{
	if ( top == NULL ) 
		return true;
	else
		return false;
} //end function isEmpty

bool Stack::push( const T &newItem ) //push nodes to the stack
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

void Stack::pop() //pop Nodes from the stack without saving content
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

void Stack::pop( T &d ) //pop Nodes from the stack
{
	if ( isEmpty() )
	{
		cerr << "The stack is empty" << endl;
	}
	else //stack is not empty
	{
		//retrieve element and pass into object
		d = top -> getData();
		
		//create temporary node
		Node *tempNode = top;
		top = top -> next;
		
		//set tempPtr to NULL
		tempPtr -> setNextPtr( NULL );

		//delete Node
		delete tempPtr;
	}	
} //end function pop


void getTop( int &d ) //get value in top without deleting
{
	if ( isEmpty() )
	{
		cerr << "The stack is empty" << endl;
	}
	else
	{
		d = top -> getData();
	} //end if

} //end function getTop
