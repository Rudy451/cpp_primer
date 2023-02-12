#include <iostream>
#include <string>
#include <memory>

using namespace std;

void s_ftn(string s){

	char *slist = new char[s.size()];

	auto k = 0;
	for(auto i = slist; i != slist + s.size() && k < s.size(); ++i){	
		i = &s[k++];
		cout << *i << endl;
	}

	delete [] slist;
	
}

int main(){

	string ex;
	cin >> ex;
	s_ftn(ex);

}
