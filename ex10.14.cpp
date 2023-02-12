#include <iostream>

using std::cout; using std::endl;

int main(){

	auto sum_ftn = [](const int num1, const int num2){return num1 + num2;};

	cout << sum_ftn(1, 2) << endl;

}
