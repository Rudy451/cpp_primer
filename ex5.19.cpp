#include <iostream>
#include <string>

using std::cin; using std::cout; using std::string; using std::min; using std::endl;

string word_1, word_2;

int main()
{
	do{
		cout << "Please enter two words: " << endl;
		if(cin >> word_1 >> word_2){
			cout << "The smaller word is " << ((word_1.size() < word_2.size()) ? word_1 : word_2) << endl;
		} else {
			cout << "ERROR: No words were keyed in!" << endl;
		}
	} while(cin);
	
}
