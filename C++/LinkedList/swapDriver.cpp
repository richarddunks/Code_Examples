//swapdriver.cpp
#include <iostream>
#include "List.h"
#include "Node.h"
#include "Student.h"
using namespace std;

int main()
{
	List stuList1;
	bool selectionInput = false;
	int swapNum1;
	int swapNum2;
	
	//input list
	stuList1.fileInput( selectionInput );
	
	//display list
	stuList1.displayAscending();
	
	//choose node to swap
	cout << "Enter the number of node1 to swap: ";
	cin >> swapNum1;

	cout << "Enter the number of node2 to swap: ";
	cin >> swapNum2;

	Node *swapNode1 = stuList1.getHeadPtr();
	Node *swapNode2 = stuList1.getHeadPtr();
	
	//advance to the first node to be swapped
	for ( int i = 1; i < swapNum1; i++ )
	{
		swapNode1 = swapNode1 -> getNextPtr();
	} //end for at position of node to be swapped

	//advance to the second node to be swapped
	for ( int i = 1; i < swapNum2; i++ )
	{
		swapNode2 = swapNode2 -> getNextPtr();
	} //end for at position of node to be swapped

	
	//perform swap function
	stuList1.swap( swapNode1, swapNode2 );
	
	//display the list
	stuList1.displayAscending();
	
} //end function main