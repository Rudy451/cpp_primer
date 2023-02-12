#include <iostream>

using std::cout; using std::endl;

int sum_ftn(int num2){

	int num1 = 1;

	auto sum = [num1](int num2){return  num1 + num2;}; 

	return sum(num2);
}

int main(){

	cout << sum_ftn(2) << endl;

}
