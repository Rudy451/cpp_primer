#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

int main(){

	vector<int> num_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	for(auto beg = num_list.rbegin(); beg != num_list.rend(); ++beg){
		cout << *beg << endl;
	}

	return 0;

}
