#include <iostream>

using namespace std;

template<typename T> void f1(T, T){}
template<typename T1, typename T2> void f2(T1, T2){}

int main(){

	int i = 0;
	int j = 42;
	int *p1 = &i;
	int *p2 = &j;
	const int *cp1 = &i;
	const int *cp2 = &j;

	// Okay: args match (pointer to int)
	f1(p1, p2);

	// Okay: each arg called separately (pointer to int)
	f2(p1, p2);

	// Okay: args match (pointer to const int)
	f1(cp1, cp2);

	// Okay: each arg called separately (pointer to const int)
	f2(cp1, cp2);

	// Error: types don't match & no conversion from second argument to first;
	f1(p1, cp1);

	// Okay: each arg called separately (pointer to int, pointer to const int);
	f2(p1, cp1);


}
