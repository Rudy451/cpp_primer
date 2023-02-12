#include <iostream>
#include <string>
#include "ex6.42.h"

using std::cin; using std::cout; using std::string; using std::endl;

int main()
{
	size_t count;
	cin >> count;
	cout << make_plural(count, "failure", "s") << endl;
}
