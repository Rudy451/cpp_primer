#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

typedef int (*mod_ptr)(int, int);

int add(int a, int b){
	return a + b;
}

int sub(int a, int b){
	return a - b;
}

int mult(int a, int b){
	return a * b;
}

int divide(int a, int b){
	return a / b;
}


int main(){

	vector<mod_ptr> mod_list;
	mod_list.push_back(add);
	mod_list.push_back(sub);
	mod_list.push_back(mult);
	mod_list.push_back(divide);

	for(int i = 0; i < mod_list.size(); ++i){
		cout << mod_list[i](2, 1) << endl;
	}

	return 0;
}
