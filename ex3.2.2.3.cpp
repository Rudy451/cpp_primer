#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

string word;
string words;

int main()
{

	while(cin >> word){
		words += " " + word;
	}

	cout << words << endl;

	return 0;
}
