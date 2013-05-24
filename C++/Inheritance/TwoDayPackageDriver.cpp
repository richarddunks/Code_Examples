//TwoDayPackageDriver.cpp

#include <iostream>
#include "TwoDayPackage.h"
#include "CustomerInfo.h"
using namespace std;

static const int MAXSIZE = 100;

int main()
{
	//variable declarations
	bool inputComplete = false;
	int input;
	//instantiate TwoDayPackage array
	TwoDayPackage *tdPackages[ MAXSIZE ];
	int tdCounter = 0; //index for tdPackages array

	while ( inputComplete == false )
	{
		//ask for type of package
		cout << "Enter selection (1 for Two Day, 99 to exit): ";
		cin >> input;
		cin.ignore();

		if ( input != 1 && input != 99 )
		{
			cerr << "Invalid selection." << endl;
		}
		else if ( input == 1 )
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
	
			tdPackages[ tdCounter ] = new TwoDayPackage( weight, costPerOunce, send, recipient );
			tdPackages[ tdCounter ] -> print();
	
		}
		else
		{
			inputComplete = true;
		} //end if
	} //end while

	//output arrays
	cout << "\nThe contents of the Two Day Packages array: " << endl;
	for ( int i = 0; i <= tdCounter; i++ )
	{
		tdPackages[ i ] -> print();
	}
	cout << endl;
	
	cout << "The number of TwoDayPackages: " << TwoDayPackage::getCount() 
		 << "\nThe total cost of all TwoDayPackages: " << TwoDayPackage::getTotalCost() << endl;
	


} // end function main