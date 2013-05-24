



/* @title	CISC2000 Inheritance Lab: Package.h
*  @desc	A base class of package information for delivery
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#ifndef PACKAGE_H
#define PACKAGE_H

#include "CustomerInfo.h"
using namespace std;

class Package
{
public:
	Package(); //default constructor
	Package( double weigh, double cost, CustomerInfo send, 
		CustomerInfo receipt );  //constructor with values
	bool setWeight( double weigh ); //set package weight
	double getWeight(); //get package weight
	bool setCostPerOunce( double cost ); //set costPerOunce
	double getCostPerOunce(); //retrieve costPerOunce
	double getPackageCost(); //retrieve cost data member
	void setPackageCost( double cost ); //set package cost
		
	//virtual member functions
	virtual ~Package(); //destructor
	virtual void calculateCost(); //calculates the cost of sending the package
	virtual void print(); //print customer information
private:
	double weight; //weight of package in ounces
	double costPerOunce; //cost per ounce to send the package
	double packageCost; //total cost of package
	CustomerInfo sender; //customer info for sender
	CustomerInfo receiver; //customer info for receiver
}; //end class Package



#endif



