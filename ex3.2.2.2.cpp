#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

string word_1;
string word_2;

int main()
{
	cin >> word_1 >> word_2;
	
	if(word_1.size() == word_2.size()){
		cout << "Match" << endl;
	} else if(word_1.size() > word_2.size()){
		cout << "First Word" << endl;
	} else{
		cout << "Second Word" << endl;
	}

	return 0;
}
