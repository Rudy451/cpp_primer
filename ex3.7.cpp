#include <iostream>
#include <string>


using std::cin; using std::cout; using std::string; using std::endl;

int main()
{

	string exp("abcdefghi");

	cout << "Original String: " << exp << endl;

	cout << "New String: ";

	for(char c: exp){
		c = 'X';
		cout << c;
	}

	cout << endl;

	return 0;	
}
