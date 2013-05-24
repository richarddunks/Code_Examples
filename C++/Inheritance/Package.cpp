



/* @title	CISC2000 Inheritance Lab: Package.cpp
*  @desc	A base class of package information for delivery
*  @auth	Richard Dunks richarddunks@gmail.com
*/


#include <iostream>
#include "Package.h"
using namespace std;

Package::Package() //default constructor
{
	weight = 0.0;
	costPerOunce = 0.0;
	packageCost = 0.0;
} //end default constructor

Package::Package( double weigh, double cost, CustomerInfo send, CustomerInfo receipt ) 
//constructor with values
{	
	weight = weigh;
	costPerOunce = cost;
	sender = send;
	receiver = receipt;
	packageCost = 0.0;
} //end constructor with values

Package::~Package() //destructor
{

} //end destructor
 
void Package::calculateCost() //calculates the cost of sending the package
{
	packageCost = weight * costPerOunce;
} //end function calculateCost

void Package::setPackageCost( double cost )
{
	packageCost = cost;
} //end function setPackageCost

double Package::getPackageCost() //gets package cost
{
	return packageCost;
} //end function getPackageCost

bool Package::setWeight( double weigh )
{
	if ( weigh >= 0.0 )
	{
		weight = weigh;
		return true;
	}
	else
	{
		cerr << "Weight is incorrect." << endl;
		return false;
	} //end if
} //end function setWeight

double Package::getWeight()
{
	return weight;
} //end function getWeight

bool Package::setCostPerOunce( double cost )
{
	if ( cost >= 0.0 )
	{
		costPerOunce = cost;
		return true;
	}
	else
	{
		cerr << "Cost per ounce is incorrect." << endl;
		return false;
	} //end if
} //end function setCostPerOunce

double Package::getCostPerOunce()
{
	return costPerOunce;
} //end function getCostPerOunce

void Package::print()
{
	cout << "Sender information:\n";
	sender.displayCustomerInfo();
	cout << endl;
	cout << "Recipient information:\n";
	receiver.displayCustomerInfo();
	
} //end function print