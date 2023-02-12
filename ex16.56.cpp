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

	return print_stuff(typeid(rest).name()...);

}

int main(){

	error_msg(cout, "Let's", "Play", "a", "Game");

}
