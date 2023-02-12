#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; using namespace std::placeholders;

void do_stuff(int i, int j){multiplies<int> temp; cout << temp(i, j) << endl;}

int main(){

	vector<int> ex {1, 2, 3, 4, 5};
	for_each(ex.begin(), ex.end(), bind(do_stuff, _1, 2));

}
