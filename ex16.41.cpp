#include <iostream>

using namespace std;

template<typename t1, typename t2> auto sum(t1 ex1, t2 ex2)->typename make_unsigned<decltype(ex1 + ex2)>::type{

	return ex1 + ex2;

}

int main(){

	long long first = 10000000;
	long long second = 1000000;
	cout << sum(first, second) << endl; 

}
