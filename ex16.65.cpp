#include <iostream>
#include <string>

using namespace std;

template<typename T> T print_stuff(T val){

	cout << "Template #1: ";
	return val;

}

template<> const char* print_stuff(const char* val){

	cout << "Template #2: ";
	return val;

}

template<> char* print_stuff(char* val){

	cout << "Template #3: ";
	return val;

}

int main(){

	char val = 'j';
	char* vals = &val;

	cout << print_stuff(val) << endl;
	cout << print_stuff("Job") << endl;
	cout << *(print_stuff(vals)) << endl;

}
