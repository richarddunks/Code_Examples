//selectionSortDriver.cpp
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
	
	//display list descending
	stuList1.displayDescending();
	
	//sort list
	stuList1.selectionSort();
	
	//display list
	stuList1.displayAscending();
	
	//display list descending
	stuList1.displayDescending();
	
} //end function main