#include <iostream>

using namespace std;

template<typename T> void f(T){cout << "FType" << endl;}
template<typename T> void f(const T*){cout << "Pointer to Const" << endl;}
template<typename T> void g(T){cout << "GType" << endl;}
template<typename T> void g(T*){cout << "Pointer to Type" << endl;}

int main(){

	int i = 42;
	int *p = &i;
	const int ci = 0;
	const int *p2 = &ci;

	g(42); // GType
	g(p); // Pointer to Type
	g(ci); // GType
	g(p2); // Pointer to Type
	f(42); // FType
	f(p); // FType (Only accepts pointers to const)
	f(ci); // FType
	f(p2); // Pointer to Const

}
