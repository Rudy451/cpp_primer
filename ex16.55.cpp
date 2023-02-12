#include <iostream>

using namespace std;

template<typename T, typename... Args> ostream &print_stuff(ostream &os, const T& val, const Args&... rest){

	cout << sizeof...(rest) << endl;
	return print_stuff(os, rest...);

}

template<typename T> void print_stuff(ostream &os, const T& val){return os << val<< ", ";}

int main(){

	print_stuff(cout, "Today", "Was", "A", "Good", "Day");

}
