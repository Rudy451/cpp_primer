#include <iostream>

using namespace std;

// Example #1:
template<typename T, typename U, typename V> void f1(T, U, V);

// Example #2:
template<typename T> T f2(int, T&);

// Example #3:
template<typename T> inline T foo(T, unsigned int*);

// Example #4:
typedef char Ctype;
template<typename Ctype> Ctype f5(Ctype a){cout << "YAY" << endl;}

int main(){

	cout << "Having Fun?" << endl;
	f5(1);
}
