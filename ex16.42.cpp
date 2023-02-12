#include <iostream>
#include <type_traits>

using namespace std;

template<typename T> void g(T&& val){}

int main(){

	int i = 0;
	const int ci = i;
	g(i * ci);

}
