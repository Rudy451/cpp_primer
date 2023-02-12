#include <iostream>
#include <string>
#include <ctype.h>

using std::cin; using std::cout; using std::string; using std::endl;

void all_caps(string word){

	for(auto &i : word){
		i = toupper(i);	
	}


}

void all_lowers(string word){
	
	for(auto &i : word){
		i = tolower(i);
	}	
}

int main()
{
	string word = "Happy";
	cout << all_caps(word) << endl;
	cout << all_lowers(word) << endl;
	return 0;

}


