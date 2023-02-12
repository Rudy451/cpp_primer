#include <iostream>

using namespace std;

struct fake_obj{

	fake_obj(string val): name(val) {}
	string name;

}

template<typename T> bool compare(const T &one, const T &two){

	return (two < one) ? 1 : (one < two) ? 0 : -1;

}

int main(){

	fake_obj one("Steve");
	fake_obj two("Joe");
	cout << compare(one, two) << endl;


}
