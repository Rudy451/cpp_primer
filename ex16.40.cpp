#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename It> auto fcn3(It beg, It end) -> decltype(*beg + 0){

	return *beg;

}

int main(){

	vector<float> ex = {7.0, 4.0, 1.0};
	cout << fcn3(ex.begin(), ex.end()) << endl;

}
