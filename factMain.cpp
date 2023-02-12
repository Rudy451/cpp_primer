#include <iostream>
#include "Chapter6.h"

using std::cin; using std::cout; using std::endl;

int main()
{
	int val;

	cout << "Please enter a number & we'll find its factorial: " << endl;
	cin >> val;
	cout << "The factorial of: " << val << " is: " << fact(val) << ". " << endl;
	return 0;	

}


