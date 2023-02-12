#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

int main(){

	vector<int>vec(25, 1);
	vec.resize(100);
	cout << vec[25] << endl;
	vec.resize(10);
	cout << vec.size() << endl;

}
