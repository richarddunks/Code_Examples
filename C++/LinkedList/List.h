



/*	@title	CISC2200 LinkedList II: List.h
*	@desc	A List class to create a list of Nodes
*	@auth	Richard Dunks richarddunks@gmail.com
*/

#ifndef LIST_H
#define LIST_H

#include "Node.h"
using namespace std;

static const int ARRAYSIZE = 20;

class List
{
public:
	List(); //default constructor
	List( const List &listToCopy ); //copy constructor
	List( const List &listToCopy, bool dir ); //copy const with flag
	~List(); //destructor
	bool isEmpty(); //check for empty list
	int getNumNodes(); //get number of nodes
	Node *getHeadPtr(); //get head pointer
	Node *getTailPtr(); //get tail pointer
	void append( Node *nPtr ); //append new node to end of list
	void insert( Node *nPtr ); //insert node into sorted position of list
	void deleteNode( int del ); //delete node from list
	void displayAscending(); //display list in ascending order
	void displayDescending( Node *currPtr ); //display list in descending order
	void manualInput(); //manual keyboard input of student information
	void fileInputInsert(); //read input file and insert into list
	void fileInputAppend(); //read input file and append to end of list
	void outputFile(); //output list to file
	void swap( Node *swapNode ); //swap node with next node in list
	void swap( Node *swapNode1, Node *swapNode2 ); //swap first node with second
	void bubbleSort(); //bubble sort list
	Node *findMax( Node *startPtr, Node *stopPtr ); //find max Node
	void selectionSort(); //selection sort list
private:
	Node *head;
	Node *tail;
	int numNodes;
}; //end class List

#endif



