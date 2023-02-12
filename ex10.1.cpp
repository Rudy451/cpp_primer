#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; using std::endl; using std::vector; using std::count;

vector<int> count_vec = {1, 2, 3, 2, 5, 2, 6, 2, 7, 2, 8, 2};

int main(){

	cout << count(count_vec.begin(), count_vec.end(), 2) << endl;

}
