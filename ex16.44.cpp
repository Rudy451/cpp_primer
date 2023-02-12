#include <iostream>
#include <type_traits>

using namespace std;

template<typename T> void g1(T val){}
template<typename T> void g2(const T& val){}

int main(){

	int i = 0;
	const int ci = i;
	// okay: int
	g1(i);
	
	// okay: const int
	g1(ci);

	// okay: int
	g1(i * ci);

	// okay
	g2(i);

	// okay
	g2(ci);

	// okay
	g2(i * ci);
}
