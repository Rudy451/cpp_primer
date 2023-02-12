#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cstring>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl; using std::begin; using std::end;

int main()
{
	int arr_one[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	vector<int> vec_one(begin(arr_one), end(arr_one));

	vector<int> vec_two(arr_one + 2, arr_one + 6);

	for(auto move = begin(vec_two); move != end(vec_two); ++move){
		cout << *move << endl;
	}
}
