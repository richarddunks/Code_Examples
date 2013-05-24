



/* @title	CISC2000 Inheritance Lab: TwoDayPackage.cpp
*  @desc	A derived class of two day package delivery
*			from base class Package.
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include "Package.h"
#include "CustomerInfo.h"
#include "TwoDayPackage.h"
using namespace std;


//define and initialize static data member at global namespace scope
int TwoDayPackage::count = 0;
double TwoDayPackage::totalCost = 0.0;

//static member function that returns number of TwoDayPackage
//objects instantiated
int TwoDayPackage::getCount()
{
	return count;
} //end static function getCount

//static member function returning totalCost of all TwoDayPackages
//objects instantiated
double TwoDayPackage::getTotalCost()
{
	return totalCost;
} //end static function getTotalCost

TwoDayPackage::TwoDayPackage() //default constructor
: Package(), //call base class default constructor
fee( 10.0 ) //member initializer for const object in class
{
	++count;//increment static data member with count of Two Day Packages
} //end constructor

TwoDayPackage::TwoDayPackage( double weigh, double cost, CustomerInfo send, CustomerInfo receipt )
: Package( weigh, cost, send, receipt ), //call base class constructor
fee( 10.0 ) //member initializer for const object in class
{
	++count;//increment static data member with count of Two Day Packages
} //end constructor with values

TwoDayPackage::~TwoDayPackage() //destructor
{

} //end destructor

void TwoDayPackage::calculateCost()
{
	double packCost = getWeight() * getCostPerOunce() + fee; //calculate the package cost
	setPackageCost( packCost );//set packageCost in base class
	totalCost += packCost; //increase the static totalCost variable by cost of package
} //end function calculateCost

void TwoDayPackage::print()
{
	Package::print();
	cout << "\nThe package weight: " << getWeight()
		 << "\nThe cost per ounce: " << getCostPerOunce()
		 << "\nThe additional fee for Two Day Delivery: " << getFee() 
		 << "\nThe total cost: " << getPackageCost() << endl;

} //end function print

double TwoDayPackage::getFee()
{
	return fee;
} //end function getFee




