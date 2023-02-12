#include <iostream>

int main()
{
	// Exercise 2.27
	int i = -1, i2 = 5, &r = 0;
	std::cout << i << r << std::endl;
	int *const p2 = &i2;
	std::cout << p2 << std::endl;
	const int j = -1, &s = 0;
	std::cout << j << s << std::endl;
	const int *const p3 = &i2;
	std::cout << p3 << std::endl;
	const int *p1 = &i2;
	std::cout << p1 << std::endl;
	const int &const r2;
	std::cout << r2 << std::endl;
	const int i3 = i, &r3 = i;
	std::cout << i3 << r3 << std::endl;

	// Exercise 2.28
	int a, *const cp;
	int *b, *const c;
	const int d, &e = d;
	const int *const p4;
	const int *p;
	
	return 0;

}
