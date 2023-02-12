#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<typename T> void print_stuff(const T& val1){cout << val1 << endl;}

template<typename T, typename ...Args> void print_stuff(const T& val1, const Args... rest){

	cout << val1 << " ";
	return print_stuff(rest...);

}

template<typename ...Args> void error_msg(ostream& os, const Args&... rest){

	return print_stuff(to_string(rest)...);

}

int main(){

	error_msg(cerr, 1, 2, 3, 4);

}
