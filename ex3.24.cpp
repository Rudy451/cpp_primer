#include <iostream>
#include <string>
#include <vector>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;


int main()
{
	int num;
	vector<int> num_list;

	while(cin >> num){
		num_list.push_back(num);
	}

	// Read a set of integers into a vector. Print the sum of each pair of adjacent elements. 
	for(auto iter = num_list.begin(); iter != num_list.end(); iter += 2){
		cout << *iter << ", " << *(iter + 1) << endl;
	}

	auto n = 1;
	auto mid = num_list.begin() + ((num_list.end() - num_list.begin()) / 2);

	// Print the sum of the first and last elements, followed by the sum of the second and second-to-last elements, and so on.
	for(auto iter = num_list.begin(); iter != mid; ++iter){
		cout << *(iter) + *(num_list.end() - n) << endl;
		++n;

	}
}
