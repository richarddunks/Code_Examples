



/* @title	CISC2000 Polymorphism Lab: PolyDriver.cpp
*  @desc	A driver program to test the functions of derived classes 
*			TwoDayPackage and OverNightPackage, both derived from base
*			class Package with composite class CustomerInfo.
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include "Package.h"
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
	Package *Packages[ MAXSIZE ];
	int packageCounter = 0;
	
	//loop until customer entry complete
	while ( inputComplete == false && packageCounter < MAXSIZE )
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
					Packages[ packageCounter ] = new TwoDayPackage( weight, costPerOunce, send, recipient );
					break;
				case 2: //OverNight Package
					Packages[ packageCounter ] = new OverNightPackage( weight, costPerOunce, send, recipient );				
					break;
				default:
					cerr << "Input error" << endl;
					break;
			} //end switch
			Packages[ packageCounter ] -> calculateCost();
			Packages[ packageCounter ] -> print();
			++packageCounter;
		} //end if
	} //end while

	//output array
	cout << "\nEnd of Day report for Packages:" << endl;
	for ( int i = 0; i < packageCounter; i++ )
	{
		Packages[ i ] -> print();
		cout << endl;
	}
	
	cout << "\nThe number of TwoDayPackages: " << TwoDayPackage::getCount() 
		 << "\nThe total cost of all TwoDayPackages: " << TwoDayPackage::getTotalCost()
		 << "\n\nThe number of OverNightPackages: " << OverNightPackage::getCount() 
		 << "\nThe total cost of all OverNightPackages: " << OverNightPackage::getTotalCost()
		 << endl;
	
} //end function main






