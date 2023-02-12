#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	vector<int> ex = {1, 3829482, 12917, 1, 3948, 288, 2838, 281818, 409403, 38204802, 0, 38595};
	greater<int> target(1024);
	count_if(ex.begin(), ex.end(), greater<int>());

}
