#include <iostream>
#include <list>
#include <algorithm>

using std::cout; using std::endl; using std::list; using std::find; using std::distance;

int main(){

	list<int> num_list = {1, 0, 3, 4, 5, 6, 7, 0, 9, 10};
	auto zero_spot = find(num_list.rbegin(), num_list.rend(), 0);
	cout << distance(num_list.begin(), zero_spot.base()) << endl;

	return 0;

}
