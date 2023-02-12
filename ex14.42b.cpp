#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; using namespace std::placeholders;

int main(){

	vector<string> ex = {"winnie", "the", "pooh"};
	cout << *(find_if(ex.begin(), ex.end(), bind(not_equal_to<string>(), _1, "pooh"))) << endl;

}
