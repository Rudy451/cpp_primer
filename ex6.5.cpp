#include <iostream>
#include "ex6.5.h"

using std::cin; using std::cout; using std::endl;

int main()
{
	int val;

	cout << "Please enter a number & we'll provide its absolute value: " << endl;
	cin >> val;
	cout << "The absolute value of: " << val << " is: " << absl(val) << ". " << endl;
	return 0;	

}


