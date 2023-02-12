#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout; using std::endl; using std::vector; using std::list; using std::find; using std::distance;

int main(){

	vector<int> num_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	list<int> num_list(num_vec.rbegin() + 3, num_vec.rbegin() + 8);
	for(auto i = num_list.begin(); i != num_list.end(); ++i){
		cout << *i << " ";
	}
	cout << endl;
	return 0;

}
