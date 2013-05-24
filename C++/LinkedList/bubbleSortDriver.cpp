//bubbleSortDriver.cpp
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
	
	//sort list
	stuList1.bubbleSort();
	
	//display list
	stuList1.displayAscending();
	
} //end function main