#include <iostream>
#include <array>
#include "ex6.21.h"

using std::cin; using std::cout; using std::endl; using std::array;

int main()
{

	int first = 2;
	int arr_list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << compare_values(&arr_list[8], first) << endl;

}
