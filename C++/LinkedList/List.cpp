


/*	@title	CISC2200 Linked List II: List.cpp
*	@desc	A List class to create a list of Nodes
*	@auth	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Student.h"
using namespace std;

List::List() //default constructor
{
	head = NULL;
	tail = NULL;
	numNodes = 0;
} //end default constructor

List::List( const List &listToCopy ) //copy constructor
{	
	head = NULL;
	tail = NULL;
	numNodes = 0;

	//while loop to process LTC
	Node *currPtrLTC = listToCopy.head;
		
	while ( currPtrLTC != NULL )
	{ 
		//extract Student object data members
		string fname = currPtrLTC -> returnFirstName();
		string midInit = currPtrLTC -> returnMidInit();
		string lname = currPtrLTC -> returnLastName();
		string socSecNum = currPtrLTC -> returnSocialSecNum();
		int a = currPtrLTC -> returnAge(); 
		
		//copy data into new Student pointer
		Student *stuPtr = new (nothrow) Student( fname, midInit, lname, 
						socSecNum, a );
			
		//Test for memory allocation failure
		if ( stuPtr != NULL ) //memory allocation successful
		{
			//pass pointer to new Node
			Node *newNode = new Node( stuPtr );
			//pass node to List
			append( newNode );
		}
		else //memory allocation failure
		{
			cout << "Error: memory could not be allocated." << endl;
		}		

		//advance currPtrLTC
		currPtrLTC = currPtrLTC -> getNextPtr();
	}  //end while at end of LTC

} //end copy constructor

List::List( const List &listToCopy, bool dir ) //copy const with flag
{
	head = NULL;
	tail = NULL;
	numNodes = 0;

	if ( dir == true ) //copy from head to tail
	{
		//while loop to process LTC
		Node *currPtrLTC = listToCopy.head;
		
		while ( currPtrLTC != NULL )
		{ 
			//extract Student object data members
			string fname = currPtrLTC -> returnFirstName();
			string midInit = currPtrLTC -> returnMidInit();
			string lname = currPtrLTC -> returnLastName();
			string socSecNum = currPtrLTC -> returnSocialSecNum();
			int a = currPtrLTC -> returnAge(); 
		
			//copy data into new Student pointer
			Student *stuPtr = new (nothrow) Student( fname, midInit, lname, 
						socSecNum, a );
			
			//Test for memory allocation failure
			if ( stuPtr != NULL ) //memory allocation successful
			{
				//pass pointer to new Node
				Node *newNode = new Node( stuPtr );
				//pass node to List
				append( newNode );
			}
			else //memory allocation failure
			{
				cout << "Error: memory could not be allocated." << endl;
			}		

			//advance currPtrLTC
			currPtrLTC = currPtrLTC -> getNextPtr();
		}  //end while at end of LTC
	}
	else //copy from tail to head
	{
		//while loop to process LTC
		Node *currPtrLTC = listToCopy.tail;
		
		while ( currPtrLTC != NULL )
		{ 
			//extract Student object data members
			string fname = currPtrLTC -> returnFirstName();
			string midInit = currPtrLTC -> returnMidInit();
			string lname = currPtrLTC -> returnLastName();
			string socSecNum = currPtrLTC -> returnSocialSecNum();
			int a = currPtrLTC -> returnAge(); 
		
			//copy data into new Student pointer
			Student *stuPtr = new (nothrow) Student( fname, midInit, lname, 
						socSecNum, a );
			
			//Test for memory allocation failure
			if ( stuPtr != NULL ) //memory allocation successful
			{
				//pass pointer to new Node
				Node *newNode = new Node( stuPtr );
				//pass node to List
				append( newNode );
			}
			else //memory allocation failure
			{
				cout << "Error: memory could not be allocated." << endl;
			}		
			
			//advance currPtrLTC
			currPtrLTC = currPtrLTC -> getPrevPtr();
		} //end while with LTC at head of list
	} //end if

} //end copy constructor with boolean flag


List::~List() //destructor
{
	if ( !isEmpty() )
	{
		cout << "Destroying Nodes...\n";
		
		Node *currPtr = head;
		Node *tempPtr;
		
		while ( currPtr != NULL ) 
		{
			tempPtr = currPtr;
			tempPtr -> displayStudentInfo(); 
			cout << endl;
			currPtr = currPtr -> getNextPtr();
			delete tempPtr;
		}  //end while
	} //end if
	cout << "All nodes destroyed\n\n";
} //end destructor

bool List::isEmpty() //check for empty list
{
	if ( head == NULL )
	{
		return true;
	}
	else
	{
		return false;
	} //end if
} //end function isEmpty

int List::getNumNodes() //get number of nodes
{
	return numNodes;
} //end function getNumNodes

Node *List::getHeadPtr()
{
	return head;
} //end function getHeadPtr

Node *List::getTailPtr()
{
	return tail;
} //end function getTailPtr

void List::append( Node *nPtr ) //append new node to end of list
{
	if ( head != NULL )
	{
		nPtr -> setPrevPtr( tail ); //points nPtr -> prev to tail of list
		tail -> setNextPtr( nPtr ); //points tail -> next to nPtr
		tail = nPtr; //sets tail to nPtr; nPtr becomes the tail of the list
	}
	else
	{
		head = nPtr;
		tail = nPtr;
	} //end if
	
	//increment the number of nodes in the list
	++numNodes;
} //end function append

void List::insert( Node *nPtr ) //insert node into sorted position of list
{	
	Node *currPtr = head;
	Node *prevPtr = tail;
	int newPtrData = nPtr -> returnAge();

	//test for an empty list
	if ( isEmpty() == true )
	{
		head = nPtr; //point head to nPtr
		tail = nPtr; //pointer tail to nPtr	
	}
	//test for nPtr data < head
	else if ( currPtr -> returnAge() > newPtrData )
	{
		nPtr -> setNextPtr( currPtr );
		currPtr -> setPrevPtr( nPtr );
		head = nPtr;
	} 
	//test for nPtr data > tail
	else if ( prevPtr -> returnAge() < newPtrData )
	{
		prevPtr -> setNextPtr( nPtr );
		currPtr -> setPrevPtr( prevPtr );
		tail = nPtr;
		
	}
	//insert into middle of list without having to change head or tail
	else
	{
		//traverse list to proper point in list
		while ( currPtr -> returnAge() < newPtrData )
		{
			currPtr = currPtr -> getNextPtr(); //advance current pointer
		} //end while
		//current pointer at next element in list

		//set previous pointer at list element <= nPtr
		prevPtr = currPtr -> getPrevPtr();		
		
		nPtr -> setNextPtr( currPtr ); //set nPtr -> next to currPtr
		nPtr -> setPrevPtr( prevPtr ); //set nPtr -> prev to prevPtr
		currPtr -> setPrevPtr( nPtr ); //set currPtr -> prev to nPtr
		prevPtr -> setNextPtr( nPtr ); //set prevPtr -> next to nPtr
	} //end if	

	//increment node counter
	++numNodes; 
} //end function insert

void List::deleteNode( int del ) //delete node from list
{
	Node *currPtr = head;
	
	int nodeCount = 1; //count for number of nodes as traverse list
	
	if ( del > numNodes || del < 1 ) //test for invalid delete operation
	{
		cout << "That node doesn't exist in the list" << endl;
	}
	else //conduct delete operation
	{
		while ( nodeCount < del )
		{
			currPtr = currPtr -> getNextPtr();
			++nodeCount;
		} //end while
			//currPtr at node to be deleted

		Node *prevPtr = currPtr -> getPrevPtr(); //pointer to node prev	to node to delete	
		Node *nextPtr = currPtr -> getNextPtr(); //pointer to node next to node to delete
		
		//reset pointers
		if ( prevPtr != NULL )
		{
			prevPtr -> setNextPtr( nextPtr );
		}
		if ( nextPtr != NULL )
		{
			nextPtr -> setPrevPtr( prevPtr );
		}

		currPtr -> setNextPtr( NULL );
		currPtr -> setPrevPtr( NULL );
		
		//test for deleted node to be head or tail
		if ( currPtr == head )
		{
			head = nextPtr;
		}
		else if ( currPtr == tail )
		{
			tail = prevPtr;
		} //end if test for head or tail deletion
		
		delete currPtr;
		//decrement node counter
		--numNodes;	
	} //end if
	

} //end function deleteNode

void List::displayAscending() //display list in ascending order
{
	Node *currPtr = head;
	
	cout << "Student List ( Ascending ): " << endl;
	while ( currPtr != NULL )
	{
		//display data members of the list
		currPtr -> displayStudentInfo();
		currPtr = currPtr -> getNextPtr();
	} //end while
	
	cout << endl; //insert blank line
} //end function displayAscending


void List::displayDescending( Node *currPtr )
{
	if ( currPtr == tail )
	{
		cout << "Student List ( Descending ): " << endl;
		currPtr -> displayStudentInfo();
	}
	else
	{
		displayDescending( currPtr -> getNextPtr() );
		currPtr -> displayStudentInfo();
	} //end if
} //end function displayDescending

void List::manualInput()
{
	string fname, midInit, lname, socSecNum, ageString; //user-inputed Student values
	int a; //user-inputed Student value
	bool continueLoop = true; //sentinel value for data entry loop
	string continueLoopInput; //user response for data entry loop
	Node *currentPtr = NULL; //traverse pointer	

	while ( continueLoop == true )
	{
		cout << "Enter student data? (Y to continue)\n";
		getline( cin, continueLoopInput );
		if ( continueLoopInput == "Y" || continueLoopInput == "y" )
		{
			int inputFlag = 0;
			
			//user input Student data
			cout << "Enter the student's first name: ";
			getline( cin, fname );
			cout << "Enter the student's middle initial: ";
			getline( cin, midInit );

			//test midInit input
			if ( midInit.length() > 1 )
			{
				inputFlag = 1;
			}			
			cout << "Enter the student's last name: ";
			getline( cin, lname );
			cout << "Enter the student's social security number: ";
			getline( cin, socSecNum);
			if ( socSecNum.length() > 9 )
			{
				inputFlag = 2;
			}
			cout << "Enter the student's age: ";
			getline(cin, ageString );
		    if ( ageString.length() > 2 )
		   	{
			  	inputFlag = 3;
		   	}
			stringstream myStream( ageString );
			myStream >> a;
			
			switch ( inputFlag )
			{
				case 0:
				{	
					//instantiate Student pointer
					Student *stuPtr = new (nothrow) Student( fname, midInit, lname, 
						socSecNum, a );
			
					//Test for memory allocation failure
					if ( stuPtr != NULL ) //memory allocation successful
					{
						//pass pointer to new Node
						currentPtr = new Node( stuPtr );
						//pass node to List
						append( currentPtr );
					}
					else //memory allocation failure
					{
						cout << "Error: memory could not be allocated." << endl;
					}
					break;
				} //end case 0
					
				case 1: //middle initial too long
					cout << "Enter only the student's middle initial." << endl;
					break;
				//end case 1
				
				case 2: //social security number too long (>9 digits in length)
					cout << "Enter a valid social security number." << endl;
					break;
				//end case 2
					
				case 3: //age greater than two digits
					cout << "Enter a valid age." << endl;
					break;
				//end case 3
				
				default: //to exit switch
					break;
				
			} //end switch
		} //end continueLoop = true condition
		else //user indicates doesn't wish to continue
		{
			continueLoop = false; //breaks while and goes to output
		} //end if
		cin.clear(); //flush the input buffer
	} //end while

} //end function manualInput


void List::fileInputInsert()
{
	char inputFilename[ ARRAYSIZE ]; //filename for input file
	string fname, midInit, lname, socSecNum, ageString; //user-inputed Student values
	int a; //user-inputed Student value
	Node *currentPtr = NULL; //traverse pointer

	//enter input filename
	cout << "Enter input filename (no more than 20 characters): ";
	cin >> inputFilename; //user-inputted file name
			
	//create object dataFile with records
	ifstream inDataFile( inputFilename, ios::in ); 
				
	//error checking for file not being opened				
	if ( !inDataFile )
	{
		cerr << "File could not be opened" << endl;
		exit( 1 );
	} //end if for error check
				
	//read in element

	while ( inDataFile.eof() != true )
	{
					
		inDataFile >> fname >> midInit >> lname >> socSecNum >> ageString;
					
		//convert ageString to int type
		stringstream myStream( ageString );
		myStream >> a;
									
		//instantiate Student pointer
		Student *stuPtr = new (nothrow) Student( fname, midInit, lname, socSecNum, a );
			
		//Test for memory allocation failure
		if ( stuPtr != NULL ) //memory allocation successful
		{
			//pass pointer to new Node
			currentPtr = new Node( stuPtr );
			//pass Node to List
			insert( currentPtr ); //insert node in proper place
		}
		else //memory allocation failure
		{
			cout << "Error: memory could not be allocated." << endl;
		}
					
	} //end while inDataFile.eof() != true 

} //end function fileInputInsert

void List::fileInputAppend()
{
	char inputFilename[ ARRAYSIZE ]; //filename for input file
	string fname, midInit, lname, socSecNum, ageString; //user-inputed Student values
	int a; //user-inputed Student value
	Node *currentPtr = NULL; //traverse pointer

	//enter input filename
	cout << "Enter input filename (no more than 20 characters): ";
	cin >> inputFilename; //user-inputted file name
			
	//create object dataFile with records
	ifstream inDataFile( inputFilename, ios::in ); 
				
	//error checking for file not being opened				
	if ( !inDataFile )
	{
		cerr << "File could not be opened" << endl;
		exit( 1 );
	} //end if for error check
				
	//read in element

	while ( inDataFile.eof() != true )
	{
					
		inDataFile >> fname >> midInit >> lname >> socSecNum >> ageString;
					
		//convert ageString to int type
		stringstream myStream( ageString );
		myStream >> a;
									
		//instantiate Student pointer
		Student *stuPtr = new (nothrow) Student( fname, midInit, lname, socSecNum, a );
			
		//Test for memory allocation failure
		if ( stuPtr != NULL ) //memory allocation successful
		{
			//pass pointer to new Node
			currentPtr = new Node( stuPtr );
			//pass Node to List
			append( currentPtr ); //insert node in proper place
		}
		else //memory allocation failure
		{
			cout << "Error: memory could not be allocated." << endl;
		}
					
	} //end while inDataFile.eof() != true 

} //end function fileInputAppend


void List::outputFile() //output report to file
{
	Node *currPtr = head; // local traverse pointer
	char outputFilename[ ARRAYSIZE ]; //filename for output file
	
	//enter output filename
	cout << "Enter output filename (no more than 20 characters): ";
	cin >> outputFilename; //user-inputted file name
	
	//instantiate ofstream object
	ofstream outDataFile( outputFilename, ios::out );		

	//check for file correctly opened
	if ( !outDataFile ) //file not correctly opened
	{
		cerr << "File could not be opened" << endl;
		exit( 1 );
	} //end if

	//output data members of current pointer	
	while ( currPtr != NULL )
	{
		outDataFile << currPtr -> returnFirstName() << " " 
			<< currPtr -> returnMidInit() << " " 
			<< currPtr -> returnLastName() << " " 
			<< currPtr -> returnSocialSecNum() << " " 
			<< currPtr -> returnAge() << endl;

		//advance the current pointer
		currPtr = currPtr -> getNextPtr();
	} //end while
	outDataFile.close();
} //end function outputFile

void List::swap( Node *swapNode1, Node *swapNode2 ) //swap two nodes in the list
{
	//test for adjacent node swap
	if ( swapNode1 -> getNextPtr() == swapNode2 )
	{
		Node *prevPtr = swapNode1 -> getPrevPtr();
		Node *nextPtr = swapNode2 -> getNextPtr();
		
		if ( prevPtr != NULL ) //test for swapNode1 head of list
		{
			prevPtr -> setNextPtr( swapNode2 );
		}
		else //swapNode1 at head of list
		{
			head = swapNode2;
		} //end if
		if ( nextPtr != NULL ) //test for swapNode2 tail of list
		{
			nextPtr -> setPrevPtr( swapNode1 );
		}
		else //swapNode2 at tail of list
		{
			tail = swapNode1;
		} //end if
		
		swapNode2 -> setPrevPtr( prevPtr );
		swapNode1 -> setNextPtr( nextPtr );
		swapNode1 -> setPrevPtr( swapNode2 );
		swapNode2 -> setNextPtr( swapNode1 );

		//swap complete
	}
	else //non-adjacent node swap
	{
		Node *prevPtr1 = swapNode1 -> getPrevPtr();
		Node *nextPtr1 = swapNode1 -> getNextPtr();
		Node *prevPtr2 = swapNode2 -> getPrevPtr();
		Node *nextPtr2 = swapNode2 -> getNextPtr();

		//test for swapNode1 being the head of the list
		if ( prevPtr1 != NULL )
		{
			prevPtr1 -> setNextPtr( swapNode2 );
		}
		else //swapNode1 is the head of the list
		{
			head = swapNode2;
		}

		//test for swapNode2 being the tail of the list
		if ( nextPtr2 != NULL )
		{
			nextPtr2 -> setPrevPtr( swapNode1 );
		}
		else //swapNode2 is the tail of the list
		{
			tail = swapNode1;
		}
	
		//fixing nextPtr1 and prevPtr2 to the new elements	
		nextPtr1 -> setPrevPtr( swapNode2 );
		prevPtr2 -> setNextPtr( swapNode1 );

		//setting the pointers of the nodes to be swapped
		swapNode2 -> setPrevPtr( prevPtr1 );
		swapNode2 -> setNextPtr( nextPtr1 );
		swapNode1 -> setPrevPtr( prevPtr2 );
		swapNode1 -> setNextPtr( nextPtr2 );
	} //end if
} //end function swap

void List::bubbleSort()
{
	int swapCount = 0;	

	do
	{
		Node *currPtr = head;
		swapCount = 0;

		//cycle through list
		while ( currPtr -> getNextPtr() != NULL )
		{
			Node *nextPtr = currPtr -> getNextPtr();
			//basic test
			if ( currPtr -> returnAge() > nextPtr -> returnAge() )
			{
				swap( currPtr, nextPtr );
				swapCount++;
			}
			else
			{
				currPtr = nextPtr;
			}
		} //end while
	} while ( swapCount != 0 ); //end while sorting loop 
	
} //end function bubbleSort

Node *List::findMax( Node *startPtr, Node *stopPtr )
{
	Node *maxPtr = startPtr;
	Node *currPtr = startPtr;

	do
	{
		currPtr = currPtr -> getNextPtr();
		if ( currPtr -> returnAge() > maxPtr -> returnAge() )
		{
			maxPtr = currPtr;
		}
	} while ( currPtr != stopPtr ); //end while
	
	return maxPtr;
} //end function findMax

void List::selectionSort()
{
	Node *sortStop = tail;
	
	while ( sortStop != head )
	{
		//find maximum Node in list
		Node *maxNode = findMax( head, sortStop );

		//test that tail isn't max
		if ( maxNode != sortStop )
		{
			//set max Node to tail of list
			swap( maxNode, sortStop );
			//reset sortStop
			sortStop = maxNode -> getPrevPtr();
		}
		else 
		{
			//regress sortStop
			sortStop = sortStop -> getPrevPtr();
		}
	} //end while

	//list sorted
	
} //end function selectionSort






