#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main(){

	vector<int> v1 = {1, 2, 3, 4};
	vector<int> v2 = {1, 2, 4};
	list<int> v3 = {1, 2, 4};

	if(v1 < v2){cout << "It Works!" << endl;}


	return 0;

}
