



/* @title	CISC2000 Inheritance Lab: OverNightPackage.cpp
*  @desc	A derived class of over night package delivery
*			from base class Package.
*  @auth	Richard Dunks richarddunks@gmail.com
*/


#include <iostream>
#include "Package.h"
#include "CustomerInfo.h"
#include "OverNightPackage.h"
using namespace std;

//define and initialize static data member at global namespace scope
int OverNightPackage::count = 0;
double OverNightPackage::totalCost = 0.0;

//static member function that returns number of TwoDayPackage
//objects instantiated
int OverNightPackage::getCount()
{
	return count;
} //end static function getCount

//static member function returning totalCost of all TwoDayPackages
//objects instantiated
double OverNightPackage::getTotalCost()
{
	return totalCost;
} //end static function getTotalCost

OverNightPackage::OverNightPackage() //default constructor
: Package(), //call base class default constructor
fee( 10.0 ) //member initializer for const object in class
{
	++count; //increment static data member counting ONP objects
} //end constructor

OverNightPackage::OverNightPackage( double weigh, double cost, CustomerInfo send, CustomerInfo receipt )
: Package( weigh, cost, send, receipt ), //call base class constructor
fee( 10.0 ) //member initializer for const object in class
{
	++count; //increment static data member counting ONP objects
} //end constructor with values

OverNightPackage::~OverNightPackage() //destructor
{

} //end destructor

void OverNightPackage::calculateCost()
{
	double packCost = getWeight() *  getCostPerOunce() * fee; //calc package cost
	setPackageCost( packCost ); //set packageCost in base class
	totalCost += packCost; //increase the static totalCost variable by cost of package
} //end function calculateCost

void OverNightPackage::print()
{
	Package::print();
	cout << "\nThe package weight: " << getWeight()
		 << "\nThe cost per ounce: " << getCostPerOunce()
		 << "\nThe additional fee for Over Night Delivery: " << getFee() 
		 << "\nThe total cost: " << getPackageCost() << endl;

} //end function print

double OverNightPackage::getFee()
{
	return fee;
} //end function getFee




