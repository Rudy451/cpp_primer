#include <iostream>
#include <vector>
#include <numeric>

using std::cout; using std::endl; using std::vector;

vector<double> v(5, 3);

int main(){

	cout << accumulate(v.cbegin(), v.cend(), 1) << endl;

}
