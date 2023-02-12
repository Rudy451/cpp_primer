#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl; using std::begin; using std::end;

int main()
{

	int arr[] = {1, 2, 3, 4, 5};

	int *arr_beg = begin(arr), *arr_end = end(arr);

	while(arr_beg != arr_end){
		cout << arr_beg << endl;
		++arr_beg;
	}

}
