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
				s.insert(i + 1, newVal);
				s.erase(start, temp.size());
			}
		}
	}
	
}

int main(){

	string s = "I'm good tho";

	string_chg(s, "tho", "though");

	cout << s << endl;

}
