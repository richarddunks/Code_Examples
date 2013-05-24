/* @title	CISC2200 Stack Lab: Node.h
*  @desc	A Node class to take a templated input.
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#ifndef NODE_H
#define NODE_H

template< typename t >
class Node
{
public:
	Node(); //default constructor
	Node( T data ); //constructor with data value
	~Node(); //destructor
	void setNextPtr( Node *nPtr ); //set next pointer
	Node *getNextPtr(); //get next pointer
	void displayStudentInfo(); //call outputStudentInfo function in class Student
private:
	T input; //content of node
	Node *next; //pointer to next element in list
}; //end class Node

//begin function definitions

//default constructor
template< typename T >
Node< T >::Node()
{
	 next = NULL;
}

//constructor with data value
template< typename T >
Node< T >::Node()



#endif




