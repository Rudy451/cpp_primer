#include <iostream>

int main()
{

	// Ex: 2.18

	// Sample variables
	int ex = 1;
	int *p_ex = &ex;
	
	// Change the value of a pointer
	ex = 2;
	std::cout << *p_ex << std::endl;
	
	*p_ex = 3;
	std::cout << *p_ex << std::endl;

	// Ex: 2.20
	int i = 42;
	int *p1 = &i;
	*p1 = *p1 * *p1;
	std::cout << *p1 << std::endl;

	return 0;
}
