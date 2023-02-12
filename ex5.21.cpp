#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstddef>
	
using std::cin; using std::cout; using std::string; using std::vector; using std::istringstream; using std::find; using std::endl;


int main()
{

	string sentence;
	getline(cin, sentence);

	istringstream iss(sentence);
	string word;
	string word2;
	auto repeat = 0;

	while(iss >> word){
		if(word == word2 && isupper(word[0]) && isupper(word2[0])){
			cout << "Duplicate is: ";
			repeat = 1;
			break;
		} else {
			word2 = word;
			continue;
		}
	}

	cout << (repeat == 1 ? word : "No Repeats!") << endl;

	return 0;
}
