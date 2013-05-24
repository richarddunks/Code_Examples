//OverNightPackageDriver.cpp

#include <iostream>
#include "OverNightPackage.h"
#include "CustomerInfo.h"
using namespace std;

static const int MAXSIZE = 100;

int main()
{
	//variable declarations
	bool inputComplete = false;
	int input;
	//instantiate OverNightPackage array
	OverNightPackage *onPackages[ MAXSIZE ];
	int onCounter = 0; //index for tdPackages array

	while ( inputComplete == false )
	{
		//ask for type of package
		cout << "Enter selection (2 for Over Night, 99 to exit): ";
		cin >> input;
		cin.ignore();

		if ( input != 2 && input != 99 )
		{
			cerr << "Invalid selection." << endl;
		}
		else if ( input == 2 )
		{
			CustomerInfo send;
			CustomerInfo recipient;
			double weight;
			double costPerOunce;
	
			cout << "Enter sender information" <<endl;
			send.enterCustomerInfo();
	
			cout << "\nEnter receiver information" << endl;
			recipient.enterCustomerInfo();
	
			cout << "\nEnter weight in ounces: ";
			cin >> weight;
	
			cout << "\nEnter cost per ounce: ";
			cin >> costPerOunce;
	
			onPackages[ onCounter ] = new OverNightPackage( weight, costPerOunce, send, recipient );
			onPackages[ onCounter ] -> print();
	
		}
		else
		{
			inputComplete = true;
		} //end if
	} //end while

	//output arrays
	cout << "\nThe contents of the Two Day Packages array: " << endl;
	for ( int i = 0; i <= onCounter; i++ )
	{
		onPackages[ i ] -> print();
	}
	cout << endl;
	
	cout << "The number of OverNightPackages: " << OverNightPackage::getCount() 
		 << "\nThe total cost of all OverNightPackages: " << OverNightPackage::getTotalCost() << endl;
	



} // end function main