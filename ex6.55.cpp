#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

// Original Function
int mod_ftn(int first, int second){
	return first * second;
}

// Function Pointer to mod_ftn address
int (*mod_ptr)(int, int) = &mod_ftn;

int main()
{
	// Call original function
	int old_func = mod_ftn(1, 2);

	// Call Function Pointer with proper parameters.
	int new_func = mod_ptr(1, 2);

	return 0;
}
