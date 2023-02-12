#include <iostream>
#include <string>


using std::cin; using std::cout; using std::string; using std::endl;

int main()
{

	string words;
	
	while(getline(cin, words)){
		cout << words << endl;
		for(auto c: words){
			if(!ispunct(c)){
				cout << c;
			}
		}
	}
	
	cout << endl;

	return 0;	
}
