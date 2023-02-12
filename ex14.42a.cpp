#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; using namespace std::placeholders;

//bool ftn_example(int i){greater<int> target; return target(i, 1024);}

int main(){

	vector<int> ex = {1, 3829482, 12917, 1, 3948, 288, 2838, 281818, 409403, 38204802, 0, 38595};
	cout << count_if(ex.begin(), ex.end(), bind(greater<int>(), _1, 1024)) << endl;

}
