#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

int main(){

	vector<int> v(2, 10);
	
	auto begin = v.begin();
	auto end = v.end();

	while(begin != v.end()){
		++begin;
		begin = v.insert(begin, 42);
		++begin;
	}

}
