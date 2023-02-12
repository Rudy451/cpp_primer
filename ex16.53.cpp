#include <iostream>

using namespace std;

template<typename T> void print_stuff(const T& val){cout << 0 << endl;}

template<typename T, typename... Args> void print_stuff(const T&val, const Args&... rest){

	cout << sizeof...(rest) << endl;
	return print_stuff(rest...);

}
/*
int main(){

	print_stuff("Today", "Was", "A", "Good", "Day");

}*/
