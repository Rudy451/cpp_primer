#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cstring>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl; using std::end;

int main()
{
	// c-string concatenation
	char uno[] = "Go";
	char dos[] = "Dav";
	char tres[10];

	strcpy(tres, uno);
	strcat(tres, " ");
	strcat(tres, dos);

	auto i = tres;

	while(i != end(tres)){
		cout << *i;
		++i;
	}

	cout << endl;

}
