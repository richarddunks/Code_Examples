/** @desc	Lab3 CISC2200 Data Structures: Student.cpp
*			A student class to hold data for use in a linked list
* @author	Richard Dunks richarddunks@gmail.com
*/
#include <iostream>
#include "Student.h"
using namespace std;

Student::Student() //default constructor
{

} //end default constructor

//constructor with values
Student::Student( string fname, string midInit, string lname, string socSecNum, int a )
{
	firstName = fname;
	middleInit = midInit;
	lastName = lname;
	socialSecNum = socSecNum;
	age = a;
} //end constructor

//function to get first name
string Student::getFirstName()
{
	return firstName;
} //end function getFirstName

//function to set first name
void Student::setFirstName( string fname )
{
	firstName = fname;
} //end function setFirstName

//function to get middle initial
string Student::getMiddleInit()
{
	return middleInit;
} //end function getMiddleInit

//function to set middle initial
void Student::setMiddleInit( string midInit )
{
	middleInit = midInit;
} //end function setMiddleInit

//function to get last name
string Student::getLastName()
{
	return lastName;
} //end function getLastName

//function to set last name
void Student::setLastName( string lname )
{
	lastName = lname;
} //end function setLastName

//function to get social security number
string Student::getSocialSecNum()
{
	return socialSecNum;
} //end function getSocialSecNum

//function to set the social security number
void Student::setSocialSecNum( string socSecNum )
{
	socialSecNum = socSecNum;
} //end function setSocialSecNum

//function to get student age
int Student::getAge()
{
	return age;
} //end function getAge

//function to set student age
void Student::setAge( int a )
{
	age = a;
} //end function setAge

//function to display student information
void Student::outputStudentInfo()
{
	cout << "Student Name: " << getFirstName() << " " 
		<< getMiddleInit() << " " << getLastName()
		<< "\nStudent Social Security Number: " << getSocialSecNum()
		<< "\nStudent Age: " << getAge() << endl;
} //end function outputStudentInfo



