#include <iostream>
#include <string>

using std::endl; using std::cout; using std::string;

void string_chg(string &s, string oldVal, string newVal){

	string temp;
	int start;

	for(auto i = 0; i < s.size(); ++i){
		if(s[i] == ' '){
			temp.clear();
			start = i + 1;
		} else {
			temp.push_back(s[i]);
			if(temp == oldVal){
				s.replace(start, temp.size(), newVal);
			}
		}
	}
	
}

int main(){

	string s = "I'm thru with talking to you, but your still my friend thru and thru";

	string_chg(s, "thru", "through");

	cout << s << endl;

}
