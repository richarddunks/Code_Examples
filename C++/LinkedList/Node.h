



/* @title	CISC2200 Linked List II: Node.h
*  @desc	A Node class to take a Student pointer.
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#ifndef NODE_H
#define NODE_H

#include "Student.h"
using namespace std;

class Node
{
public:
	Node(); //default constructor
	Node( Student *stuPtr ); //constructor with data value
	~Node(); //destructor
	void setNextPtr( Node *nPtr ); //set next pointer
	Node *getNextPtr(); //get next pointer
	void setPrevPtr( Node *pPtr ); //set previous pointer
	Node *getPrevPtr(); //get previous pointer
	void displayStudentInfo(); //call outputStudentInfo function in class Student
	string returnFirstName(); //call getFirstName function in class Student
	string returnMidInit(); //call getMiddleInit function in class Student
	string returnLastName(); //call getLastName function in class Student
	string returnSocialSecNum(); //call getSocialSecNum function in class Student
	int returnAge(); //call getAge function in class Student
private:
	Student *sPtr; //content of node
	Node *next; //pointer to next element in list
	Node *prev; //pointer to previous element in list
}; //end class Node

#endif




