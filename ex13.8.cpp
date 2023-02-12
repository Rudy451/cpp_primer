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
	~HasPtr(){};
	string *ps;
	int i;

};

int main(){

	HasPtr first("Sherlock Holmes");
	HasPtr *second = new HasPtr;
	delete(second);

}
