//findMaxDriver.cpp

#include <iostream>
#include "List.h"
#include "Node.h"
#include "Student.h"
using namespace std;

int main()
{
	List stuList1;
	bool selectionInput = false;

	//input list
	stuList1.fileInput( selectionInput );

	//display list
	stuList1.displayAscending();
	
	//get head of list
	cout << "Getting head pointer..." << endl;
	Node *headPtr = stuList1.getHeadPtr();
	cout << "Getting tail pointer..." << endl;
	Node *tailPtr = stuList1.getTailPtr();
	
	//find max list
	cout << "Calling findMax()..." << endl;
	Node *maxNode = stuList1.findMax( headPtr, tailPtr );
	
	//display max
	cout << "Displaying maxNode result..." << endl;
	maxNode -> displayStudentInfo();
	
} //end function main