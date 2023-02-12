#include <iostream>
#include <array>
#include "ex6.22.h"

using std::cin; using std::cout; using std::endl; using std::array;

int main()
{

	int first_arr[5] = {1, 2, 3, 4, 5};
	int second_arr[5] = {6, 7, 8, 9, 10};
	switch_values(&first_arr[2], &second_arr[2]);
	cout << "First array, third position=" << first_arr[2] << ". Second array, third position=" << second_arr[2] << endl;
	return 0;

}
