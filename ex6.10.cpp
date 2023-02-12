#include <iostream>
#include "ex6.10.h"

using std::cin; using std::cout; using std::endl;

int primero = 1, segundo = 2;
int *first = &primero, *second = &segundo;

int main()
{
	swap_stuff(first, second);
	cout << "first value is: " << *first << ", second value is: " << *second << endl;
	return 0;
}	
