#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

string word;
string sent;

int main()
{
//	while(cin >> word){
//		cout << word << endl;
//	}

	while(getline(cin, sent)){
		cout << sent << endl;
	}

	return 0;
}
