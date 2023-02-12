#include <iostream>
#include <string>
#include <vector>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	string word;
	vector<string> word_list;

	while(cin >> word){
		word_list.push_back(word);
	}

	for(string word_it : word_list){
		cout << word_it << " ";
	}

	cout << endl;

	return 0;	
}
