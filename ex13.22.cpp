#include <iostream>
#include <string>

using namespace std;

struct HasPtr{
	HasPtr(const HasPtr& orig): ps(new string(*orig.ps)), i(orig.i) {}
	HasPtr& operator=(HasPtr& orig){
		 ps = new string(*orig.ps);
		 i = orig.i;
	}
	HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
	~HasPtr(){delete ps;};
	string *ps;
	int i;

};

int main(){

	HasPtr first("Sherlock Holmes");
	HasPtr second(first);
	*(second.ps) = "John Watson";
	cout << *(first.ps) << endl;
	cout << *(second.ps) << endl;
	cout << second.i << endl;

}
