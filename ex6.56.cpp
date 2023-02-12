#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

// Original functions
int prd_ftn(int first=1, int second=2){
	return first * second;
}

int div_ftn(int first, int second){
	return first / second;
}

typedef decltype(prd_ftn) *prd_ptr;

// Function with function pointer as parameter
int new_ftn(int math_ftn(int, int), int first, int second){
	return math_ftn(first, second);
}

int main()
{
	cout << new_ftn(prd_ftn, 4, 2) << endl;
	cout << new_ftn(div_ftn, 4, 2) << endl;	

	return 0;
}
