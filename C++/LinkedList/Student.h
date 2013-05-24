/**	@desc	Lab#3A CISC2200 Data Structures: Student.h
*			A class definition for student data to be included
*			in a linked list lab exercise
* @author	Richard Dunks richarddunks@gmail.com
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
public:
	Student(); //default constructor
	Student( string fname, string midInit, string lname, string socSecNum, int a );
	//constructor with values
	void setFirstName( string fname );
	string getFirstName();
	void setMiddleInit( string midInit);
	string getMiddleInit();
	void setLastName( string lname );
	string getLastName();
	void setSocialSecNum( string socSecNum );
	string getSocialSecNum();
	void setAge( int a );
	int getAge();
	void outputStudentInfo(); //output student information	
private:
	string firstName; //student's first name
	string middleInit; //student's middle initial
	string lastName; //student's last name
	string socialSecNum; //student's SSN stored in string
	int age; //student's age
}; //end class Student

#endif



