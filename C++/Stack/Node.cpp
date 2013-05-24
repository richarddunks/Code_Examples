


/* @title	CISC2200 Linked List II: Node.cpp
*  @desc	A Node class to take a Student pointer.
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include "Node.h"
#include "Student.h"
using namespace std;

Node::Node() //default constructor
{
	next = NULL;
	prev = NULL;
	sPtr = NULL;

} //end default constructor

Node::Node( Student *stuPtr ) //constructor with data value
{
	next = NULL;
	prev = NULL;
	sPtr = stuPtr;
} //end constructor with value

Node::~Node() //destructor
{
	if ( sPtr )
	{
		delete sPtr;
	} //end if
} //end destructor

void Node::setNextPtr( Node *nPtr ) //set next pointer
{
	next = nPtr;
} //end function setNextPtr

Node *Node::getNextPtr() //get next pointer
{
	return next;
} //end function getNextPtr

void Node::setPrevPtr( Node *pPtr ) //set previous pointer
{
	prev = pPtr;
} //end function setPrevPtr

Node *Node::getPrevPtr() //get previous pointer
{
	return prev;
} //end function getPrevPtr

void Node::displayStudentInfo() //call outputStudentInfo function in class Student
{
	sPtr -> outputStudentInfo();
} //end function displayStudentInfo

string Node::returnFirstName() //call getFirstName function in class Student
{
	return sPtr -> getFirstName();
} //end function returnFirstName

string Node::returnMidInit()
{
	return sPtr -> getMiddleInit();
} //end function returnMidInit

string Node::returnLastName()
{
	return sPtr -> getLastName();
} //end function returnLastName

string Node::returnSocialSecNum()
{
	return sPtr -> getSocialSecNum();
} //end function returnSocialSecNum

int Node::returnAge() //call getAge function in class Student
{
	return sPtr -> getAge();
} //end function returnAge






