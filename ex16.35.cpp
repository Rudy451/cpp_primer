#include <iostream>

using namespace std;

template<typename T> void calc(T, int){}
template<typename T> void fcn(T, T){}

int main(){

	double d = 1.0;
	float f = 2.0;
	char c = 'c';

	// Okay: T is called with char arg and normal arithmetic conversions apply for second arg.
	calc(c, 'c');

	// Okay: T is called with double arg and normal arithmetic conversions apply for second arg.
	calc(d, f);

	// Okay: Both variables are chars.
	fcn(c, 'c');

	// Error: argument types don't match.
	fcn(d, f);

}
