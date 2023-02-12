#include <iostream>
#include <vector>

using namespace std;

class NoDefault{

public:
	NoDefault(string ex): s(ex) {} 
private:
	string s;
};

int main(){

	vector<NoDefault> vec_stuff;
	NoDefault ex("Derp");
}
