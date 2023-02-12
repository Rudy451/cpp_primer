#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cstring>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	// string comparison
	string one = "Happy";
	string two = "Happy";

	if(one == two){
		cout << "Match" << endl;
	} else {
		cout << "Fail" << endl;
	}

	// c-string comparison
	const char uno[] = "Happy";
	const char dos[] = "Joy";

	strcmp(uno, dos);

	if(strcmp(uno, dos) == 0){
		cout << "Match" << endl;
	} else {
		cout << "Fail" << endl;
	}

}
