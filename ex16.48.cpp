#include <iostream>

using namespace std;

int add(int one, int two);
template<typename t1, typename t2> auto add(const t1& one, const t2& two) -> typename remove_reference<decltype(one)>::type;
template<typename t1, typename t2> t1 add(const t1 *one, const t2 *two);

int add(int one, int two){

	cout << "Non-Template: ";
	return one + two;

}

template<typename t1, typename t2> auto add(const t1& one, const t2& two) -> typename remove_reference<decltype(one)>::type {

	cout << "Const Template: ";
	return one + two;

}

template<typename t1, typename t2> t1 add(t1 *one, t2 *two){

	cout << "Pointer Template: ";
	auto val = *(one) + *(two);
	return val;

}

int main(){

	int i = 7;
	int *j = &i;
	cout << add(j, j) << endl;

}
