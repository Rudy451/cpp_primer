#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	unsigned long ul1 = 3, ul2 = 7;
	cout << (ul1 & ul2) << endl;
	cout << (ul1 | ul2) << endl;
	cout << (ul1 && ul2) << endl;
	cout << (ul1 || ul2) << endl;
}


