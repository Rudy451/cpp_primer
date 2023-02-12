#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; using namespace std::placeholders;

int main(){

	vector<int> ex{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << (count_if(ex.begin(), ex.end(), bind(modulus<int>(), _1, 2)) > 0) << endl;;

}
