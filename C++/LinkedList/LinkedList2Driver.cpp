



/*	@title	CISC2200 Linked List II: LinkedList2Driver.cpp
*	@desc	A driver program to test the functionality of a 
*			List Class of Node Objects pointing to Student
*			objects in dynamic memory.
*	@auth	Richard Dunks richarddunks@gmail.com
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Student.h"
using namespace std;

int main()
{

	//variable declaration
	List stuList1; //instantiate List object
	int dataInputSelection; //indicator of input method
	int delNode; //number of the Node to be deleted
	bool selectionInput = false; //sentinel value to control data input method loop
	
	//begin program execution
	while ( selectionInput == false )
	{
		cout << "Enter 0 to input student information manually or "
			<< "\nEnter 1 to input student information from a file\n";
		cin >> dataInputSelection;
		cin.ignore();


		//call input type based on selection
		if ( dataInputSelection == 0 )
		{
			//call manual input function
			stuList1.manualInput( selectionInput );
		}
		else if ( dataInputSelection == 1 )
		{
			//call file input function
			stuList1.fileInput( selectionInput );
		}
		else
		{
			cout << " Invalid entry. Please select again.";
		} //end if for file input
	} //end while data input selection loop
	
	//display list ascending
	stuList1.displayAscending();
	
	//display list descending
	cout << "Student list ( Descending ): " << endl;
	Node *startPtr = stuList1.getHeadPtr();
	stuList1.displayDescending( startPtr );
	
	//get numNodes
	int nodeCount = stuList1.getNumNodes();
	cout << "The number of nodes in the list: " << nodeCount << endl;
	cout << endl;

	//test delete
	cout << "Enter the number of the student to delete" << endl;
	cin >> delNode;
	
	//call delete function
	stuList1.deleteNode( delNode );
	
	//display list ascending
	cout << "Student List after deletion:" << endl;
	stuList1.displayAscending();


	//test copy constructor
	cout << "Test copy constructor with Student List 2..." << endl;
	List stuList2 = stuList1;
	
	cout << "Student List 2: " << endl;
	stuList2.displayAscending();
	
	cout << "Student List 1: " << endl;
	stuList1.displayAscending();

	//input to second list
	selectionInput = false; //reset selection input
	cout << "Enter information into Student List 2" << endl;
	while ( selectionInput == false )
	{
		cout << "Enter 0 to input student information manually or "
			<< "\nEnter 1 to input student information from a file\n";
		cin >> dataInputSelection;
		cin.ignore();


		//call input type based on selection
		if ( dataInputSelection == 0 )
		{
			//call manual input function
			stuList2.manualInput( selectionInput );
		}
		else if ( dataInputSelection == 1 )
		{
			//call file input function
			stuList2.fileInput( selectionInput );
		}
		else
		{
			cout << " Invalid entry. Please select again.";
		} //end if for file input
	} //end while data input selection loop

	//display second list
	cout << "Student List 2 after input:" << endl;
	stuList2.displayAscending();

	//test copy constructor with boolean flag
	cout << "Test copy constructor with boolean flag with Student List 3..." << endl;
	List stuList3( stuList2, false );
	
	//display list 3
	stuList3.displayAscending();

	cout << "Test file output..." << endl;
	//file output
	stuList3.outputFile();

} //end function main






