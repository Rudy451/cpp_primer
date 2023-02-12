#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

int main(){

	vector<int> num_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	for(auto beg = num_list.end() - 1; beg != num_list.begin() - 1; --beg){
		cout << *beg << endl;
	}

	return 0;

}
