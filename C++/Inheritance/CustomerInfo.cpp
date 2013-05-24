



/* @title	CISC2000 Inheritance Lab: CustomerInfo.cpp
*  @desc	A class to contain customer information for 
*			package delivery
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include <string>
#include "CustomerInfo.h"
using namespace std;

CustomerInfo::CustomerInfo() //default constructor
{
	firstName = "";
	lastName = "";
	streetAddress = "";
	city = "";
	state = "";
	zipCode = "00000";
	
} //end default constructor

CustomerInfo::CustomerInfo( string fname, string lname, string streetAddr, 
		string cit, string st, string zip )
{
	firstName = fname;
	lastName = lname;
	streetAddress = streetAddr;
	city = cit;
	state = st;
	zipCode = zip;
		
} //end constructor with values
		
void CustomerInfo::setFirstName( string fname )
{
	firstName = fname;
} //end function setFirstName

string CustomerInfo::getFirstName()
{
	return firstName;
} //end function getFirstName

void CustomerInfo::setLastName( string lname )
{
	lastName = lname;
} //end function setLastName

string CustomerInfo::getLastName()
{
	return lastName;
} //end function getLastName

void CustomerInfo::setStreetAddress( string streetAddr )
{
	streetAddress = streetAddr;
} //end function setStreetAddress

string CustomerInfo::getStreetAddress()
{
	return streetAddress;
} //end function getStreetAddress

void CustomerInfo::setCity( string cit )
{
	city = cit;
} //end function setCity

string CustomerInfo::getCity()
{
	return city;
} //end function getCity

void CustomerInfo::setState( string st )
{
	state = st;
} //end function setState

string CustomerInfo::getState()
{
	return state;
} //end function getState

void CustomerInfo::setZipCode( string zip )
{
	zipCode = zip;
} //end function setZipCode

string CustomerInfo::getZipCode()
{
	return zipCode;
} //end function getZipCode

void CustomerInfo::enterCustomerInfo()
{
	string input;
	
	cout << "Enter customer's first name: ";
	getline( cin, input );
	setFirstName( input );
	
	cout << "Enter customer's last name: ";
	getline( cin, input );
	setLastName( input );
	
	cout << "Enter the customer's street address: ";
	getline( cin, input );
	setStreetAddress( input );
	
	cout << "Enter the customer's city: ";
	getline( cin, input );
	setCity( input );
	
	cout << "Enter the customer's state: ";
	getline( cin, input );
	setState( input );
	
	cout << "Enter the customer's zip code: ";
	getline( cin, input );
	setZipCode( input );
	
} //end function enterCustomerInfo

void CustomerInfo::displayCustomerInfo()
{
	cout << "Customer First Name: " << getFirstName()
		 << "\nCustomer Last Name: " << getLastName()
		 << "\nCustomer Street Address: " << getStreetAddress()
		 << "\nCustomer City: " << getCity()
		 << "\nCustomer State: " << getState()
		 << "\nCustomer Zip Code: " << getZipCode() << endl;
} //end function displayCustomerInfo




