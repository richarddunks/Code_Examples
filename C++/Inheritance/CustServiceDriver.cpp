



/* @title	CISC2000 Inheritance Lab: CustServiceDriver.cpp
*  @desc	A driver program to test the functions of derived classes 
*			TwoDayPackage and OverNightPackage, both derived from base
*			class Package with composite class CustomerInfo.
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include "OverNightPackage.h"
#include "TwoDayPackage.h"
#include "CustomerInfo.h"
using namespace std;

static const int MAXSIZE = 100;

int main ()
{
	//variable declarations
	bool inputComplete = false;
	int input;
	//instantiate TwoDayPackage array
	TwoDayPackage *tdPackages[ MAXSIZE ];
	int tdCounter = 0;
	//instantiate OverNightPackage array
	OverNightPackage *onPackages[ MAXSIZE ];
	int onCounter = 0;
	
	//loop until customer entry complete
	while ( inputComplete == false && tdCounter < MAXSIZE && onCounter < MAXSIZE )
	{
		//ask for type of package
		cout << "Enter selection (1 for Two Day, 2 for Over Night, 3 to exit): ";
		cin >> input;
		cin.ignore(); //flush input buffer
		
		//test input
		if ( input < 1 || input > 3 )
		{
			cerr << "Invalid selection." << endl;
		}
		else if ( input == 3 )
		{
			inputComplete = true;
		}
		else
		{
			CustomerInfo send;
			CustomerInfo recipient;
			double weight;
			double costPerOunce;

			//get package information	
			cout << "\nEnter sender information" <<endl;
			send.enterCustomerInfo();
	
			cout << "\nEnter receiver information" << endl;
			recipient.enterCustomerInfo();
	
			cout << "\nEnter weight in ounces: ";
			cin >> weight;
	
			cout << "Enter cost per ounce: ";
			cin >> costPerOunce;

			//pass to correct array type
			switch (input)
			{
				case 1: //Two Day Package
					tdPackages[ tdCounter ] = new TwoDayPackage( weight, costPerOunce, send, recipient );
					tdPackages[ tdCounter ] -> calculateCost();
					tdPackages[ tdCounter ] -> print();
					++tdCounter;
					break;
				case 2: //OverNight Package
					onPackages[ onCounter ] = new OverNightPackage( weight, costPerOunce, send, recipient );				
					onPackages[ onCounter ] -> calculateCost();
					onPackages[ onCounter ] -> print(); 
					++onCounter;
					break;
				default:
					cerr << "Input error" << endl;
					break;
			} //end switch
		} //end if
	} //end while

	//output arrays
	cout << "\nEnd of Day report for Two Day Packages:" << endl;
	for ( int i = 0; i < tdCounter; i++ )
	{
		tdPackages[ i ] -> print();
		cout << endl;
	}
	
	cout << "\nThe number of TwoDayPackages: " << TwoDayPackage::getCount() 
		 << "\nThe total cost of all TwoDayPackages: $" << TwoDayPackage::getTotalCost() << endl;
	
	cout << "\nEnd of Day report for Over Night Packages:" << endl;
	for ( int i = 0; i < onCounter; i++ )
	{
		onPackages[ i ] -> print();
		cout << endl;
	}

	
	cout << "\nThe number of OverNightPackages: " << OverNightPackage::getCount() 
		 << "\nThe total cost of all OverNightPackages: $" << OverNightPackage::getTotalCost() << endl;
	cout << endl;
	
} //end function main






