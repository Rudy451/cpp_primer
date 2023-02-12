#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cstring>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl; using std::begin; using std::end;

int main()
{
	vector<int> vec_one{1, 2, 3, 4, 5, 6, 7};
	int arr_one[7];


	for(size_t i : vec_one){
		arr_one[i] = i;
		cout << arr_one[i] << endl;
	}	
}
