#include <iostream>
#include <cassert>

#define NDEBUG = TRUE

using std::cout; using std::endl;

void print_number(const int i){
	#ifndef NDEBUG
		assert(i < 9);
	#endif
		cout << (i + 1) << endl;
}	

