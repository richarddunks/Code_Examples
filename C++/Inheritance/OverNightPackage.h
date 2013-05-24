



/* @title	CISC2000 Inheritance Lab: OverNightPackage.h
*  @desc	A derived class of over night package delivery
*			from base class Package.
*  @auth	Richard Dunks richarddunks@gmail.com
*/


#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"
#include "CustomerInfo.h"
using namespace std;


class OverNightPackage: public Package
{
public:
	OverNightPackage(); //default constructor
	OverNightPackage( double weigh, double cost, CustomerInfo send, CustomerInfo receipt );
	~OverNightPackage(); //destructor
	void calculateCost();
	void print();
	double getFee();
	static int getCount(); //retrieve static data member count
	static double getTotalCost(); //retrieve static data member totalCost
private:
	const double fee;
	static int count;
	static double totalCost;
}; //end class OverNightPackage

#endif



