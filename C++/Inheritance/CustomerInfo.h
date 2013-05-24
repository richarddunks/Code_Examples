



/* @title	CISC2000 Inheritance Lab: CustomerInfo.h
*  @desc	A class to contain customer information for 
*			package delivery
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H

#include <string>
using namespace std;

class CustomerInfo
{
public:
	CustomerInfo(); //default constructor
	CustomerInfo( string fname, string lname, string streetAddr, 
		string cit, string st, string zip );
	void setFirstName( string fname );
	string getFirstName();
	void setLastName( string lname );
	string getLastName();
	void setStreetAddress( string streetAddr );
	string getStreetAddress();
	void setCity( string cit );
	string getCity();
	void setState( string st );
	string getState();
	void setZipCode( string zip );
	string getZipCode();
	void enterCustomerInfo();
	void displayCustomerInfo();
private:
	string firstName;
	string lastName;
	string streetAddress;
	string city;
	string state;
	string zipCode;
	
}; //end class CustomerInfo


#endif



