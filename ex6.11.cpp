#include <iostream>
#include "ex6.11.h" 

using std::cout; using std::endl;

int temp_var = 32;

int main()
{
	reset(temp_var);
	cout << "Reset value is: " << temp_var << endl;
	return 0;
}	
