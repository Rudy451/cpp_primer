#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using std::cout; using std::endl; using std::vector; using std::list; using std::unique_copy; using namespace std::placeholders;

int main(){

	vector<int> first_vec = {12, 9, 8, 6, 5, 5};
	list<int> sec_vec;
	unique_copy(first_vec.begin(), first_vec.end(), sec_vec.end());
	for(auto it = sec_vec.begin(); it != sec_vec.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

}
