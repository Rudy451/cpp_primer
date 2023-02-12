#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{

	int i = 1; double d = 4.5;

	i *= static_cast<int>(d);

	cout << i << endl;

}


