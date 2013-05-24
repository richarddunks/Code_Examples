//char to int test: chIntTest.cpp

#include <iostream>
using namespace std;

int main()
{
	char ch = '4';
	int chInt = ch - '0';
	
	cout << "The value of ch is: " << ch 
		 << "\nThe value of chInt is: " << chInt << endl;
}