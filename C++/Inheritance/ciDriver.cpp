//ciDriver.cpp

#include <iostream>
#include "CustomerInfo.h"
using namespace std;

int main()
{
	CustomerInfo cust1;
	
	cust1.enterCustomerInfo();
	cout << endl;
	cust1.displayCustomerInfo();
} //end function main