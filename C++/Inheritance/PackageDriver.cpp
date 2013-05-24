//PackageDriver.cpp

#include <iostream>
#include "Package.h"
#include "CustomerInfo.h"
using namespace std;

int main()
{
	CustomerInfo send;
	CustomerInfo recipient;
	double weight;
	double costPerOunce;
	
	cout << "Enter sender information" <<endl;
	send.enterCustomerInfo();
	
	cout << "Enter receiver information" << endl;
	recipient.enterCustomerInfo();
	
	cout << "Enter weight in ounces: ";
	cin >> weight;
	
	cout << "Enter cost per ounce: ";
	cin >> costPerOunce;
	
	Package newPackage( weight, costPerOunce, send, recipient );
	
	
	double cost = newPackage.calculateCost();
	cout << "\nThe cost of the package is: " << cost << endl;
	cout << endl;
	newPackage.print();
	
	

} // end function main