#include <iostream>
#include "ex6.47.h"

using std::cout; using std::endl;

int ia[10];

int main(){
	for(int i = 0; i != 10; ++i){
		ia[i] = i;
		print_number(i);
	}
}
