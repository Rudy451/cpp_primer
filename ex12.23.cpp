#include <iostream>
#include <string>
#include <memory>

using std::cout; using std::endl; using std::string;

void s_ftn(const string s1, const string s2, string s){

	char *slist = new char[s.size()];

	auto k = 0;
	for(auto i = slist; i != slist + s.size() && k < s.size(); ++i){	
		i = &s[k++];
		cout << *i << endl;
	}

	delete [] slist;
	
}

int main(){

	const char *s1 = "Let's play ";
	const char *s2 = "a game.";
	s_ftn(s1, s2, string(s1) + string(s2));

	string s3 = "Let's play ";
	string s4 = "a game.";
	s_ftn(s3, s4, s3 + s4);

}
