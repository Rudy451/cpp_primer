#include <iostream>

using std::cout; using std::endl;

void f(){
	cout << "The First Function" << endl;
}

void f(int num){
	cout << "The Second Function" << endl;
}

void f(int num, int num2){
	cout << "The Third Function" << endl;
}

void f(double num1, double num2){
	cout << "The Fourth Function." << endl;
}

int main()
{

	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);



}
