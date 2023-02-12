#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int val, sum = 0;

int main()
{
	// block method
	while(val < 10){
		sum += val; // assigns sum + val to sum
		++val;
		cout << "val: " << val << ", sum: " << sum << endl;
	}

	// comma operator
	val = 0; 
	sum = 0;
	while(val < 10) sum += val, ++val; // assigns sum + val to sum
	cout << "val: " << val << ", sum: " << sum << endl;
}


