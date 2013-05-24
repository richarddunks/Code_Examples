



/* @title	CISC2000 Inheritance Lab: TwoDayPackage.h
*  @desc	A derived class of two day package delivery
*			from base class Package.
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"
#include "CustomerInfo.h"
using namespace std;

class TwoDayPackage: public Package
{
public:
	TwoDayPackage(); //default constructor
	TwoDayPackage( double weigh, double cost, CustomerInfo send, CustomerInfo receipt );
	~TwoDayPackage(); //destructor
	void calculateCost();
	void print();
	double getFee();
	static int getCount(); //retrieve static data member count
	static double getTotalCost(); //retrieve static data member totalCost
private:
	const double fee; //flat fee for two-day service
	double cost; //cost for package
	static int count;
	static double totalCost;
}; //end class TwoDayPackage

#endif



