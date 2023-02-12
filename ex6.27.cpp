#include <iostream>

using std::cin; using std::cout; using std::initializer_list; using std::endl;

int num_sum(initializer_list<int> num_list){
	
	int total = 0;

	for(const auto elem : num_list){
		total += elem;
	}

	cout << "Total: " << total << endl;
}

int main()
{

	num_sum({1, 2, 3, 4});	
	return 0;
}
