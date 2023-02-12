#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	const char *cp = "Hello World";
	if(cp && *cp){
		cout << cp << endl;
		cout << *cp << endl;
	}
}


