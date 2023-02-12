#include <iostream>
#include <string>
#include <list>
#include <vector>

using std::string; using std::vector; using std::list;

int main(){

	list<char*> v1 = {"A", "B", "C"};
	vector<string> v2;
	v2.assign(v1.begin(), v1.end());

	return 0;

}
