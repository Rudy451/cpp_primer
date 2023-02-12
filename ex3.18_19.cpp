#include <iostream>
#include <string>
#include <vector>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	// Exercise 3.18
	vector<int> ivec(1);
	ivec[0] = 42;
	cout << ivec[0] << endl;

	// Exercise 3.19
	vector<int> ex1(10, 42);
	vector<int> ex2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
	vector<int> ex3(10);
	for(int i = 0; i < ex3.size(); ++i){
		ex3[i] = 42;
		cout << ex1[i] << endl;
		cout << ex2[i] << endl;
		cout << ex3[i] << endl;
	}

}
