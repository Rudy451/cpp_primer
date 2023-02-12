#include <iostream>
#include <vector>
#include <numeric>

using std::cout; using std::endl; using std::vector;

int main(){

	vector<int> vec_sum(10, 5);
	int total = 0;

	cout << accumulate(vec_sum.begin(), vec_sum.end(), total) << endl;

}
