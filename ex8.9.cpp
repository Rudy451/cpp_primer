#include <iostream>
#include <string>
#include <sstream>

using std::istream; using std::string; using std::cin; using std::cout; using std::endl; using std::istringstream;

string word;

istream &random_ftn(istream &input, string word){
	while(input >> word){
		auto old_stream = input.rdstate();
		input.clear();
		cout << word << endl;
		input.setstate(old_stream);
	}
	return input;

}

int main(){
	istringstream s("The Name of the Game");
	random_ftn(s, word);
	return 0;
}
