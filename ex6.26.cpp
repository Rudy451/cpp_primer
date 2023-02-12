#include <iostream>
#include <string>

using std::cin; using std::cout; using std::string; using std::endl;

int main(int argc, char **argv)
{
	// string
	for(int i = 1; i < argc; ++i){
		cout << argv[i] << " ";
	}
		
	cout << endl;
		
	return 0;
}
