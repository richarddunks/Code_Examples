


/* @title	CISC2200 Data Structures: lab3Driver.cpp
*  @desc	A program to test the implementation of a linked
*			List using the Node and Student class and including
*			Bubble Sort and Selection Sort functions.
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include "List.h"
#include "Node.h"
#include "Student.h"

int main()
{
	List stuList1; //sorted list
	List stuList2; //unsorted list
	int delNode;
	
	//read in test file and build sorted list
	stuList1.fileInputInsert();
	
	//display sorted list ascending
	cout << "Student List #1" << endl;
	stuList1.displayAscending();
	
	//delete Christine node
	cout << "Enter number of node to delete: ";
	cin >> delNode;
	stuList1.deleteNode( delNode );
	
	//display sorted list ascending
	cout << "Student List #1 without Christine" << endl;
	stuList1.displayAscending();
	
	//read in test file "as is"
	stuList2.fileInputAppend();
	
	//invoke copy constructor to create List 3 as reverse of List2
	List stuList3( stuList2, false );
	
	//display list 2 from head to tail
	cout << "Student List #2 display Ascending" << endl;
	stuList2.displayAscending();
	
	//display list 3 from tail to head
	Node *headPtr = stuList3.getHeadPtr();
	cout << "Student List #3 display Descending" << endl;
	stuList3.displayDescending( headPtr );
	
	//delete Christine node from list 2
	cout << "Enter number of node in List #2 to delete: ";
	cin >> delNode;
	stuList2.deleteNode( delNode );

	//sort list 2 using selection sort
	stuList2.selectionSort();

	//display list 2 ascending
	cout << "Student List #2 after Selection Sort:" << endl;
	stuList2.displayAscending();
	
	//sort list 3 using bubble sort
	stuList3.bubbleSort();
	
	//display list 3
	cout << "Student List #3 after Bubble Sort:" << endl;
	stuList3.displayAscending();

} //end function main




