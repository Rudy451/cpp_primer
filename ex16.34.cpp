#include <iostream>
#include <string>

using namespace std;

template<class T> int compare(const T&, const T&){return 0;}



int main(){

	// Error: variable is const char{} so different char lengths will cause error
	compare("hi", "world");

	// Okay 
	compare("bye", "dad");

}
