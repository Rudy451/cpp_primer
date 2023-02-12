#include <iostream>
#include <vector>

using namespace std;

template<typename T> void g(T&& val){vector<T> v;}

int main(){

	int val = 42;
	g(42);
	//g(val);
}
