#include <iostream>
#include <vector>
#include <list>

using std::cin; using std::cout; using std::endl; using std::vector; using std::list;

int main(){

	vector<int> vec;
	list<int> lst;
	int i;

	while(cin >> i){
		lst.push_back(i);	
	}

	vec.resize(lst.size());

	copy(lst.cbegin(), lst.cend(), vec.begin());

	for(int i = 0; i < vec.size(); ++i){
		cout << vec[i] << endl;
	}

	return 0;

	vector<int> vec2;
	vec.reserve(10);
	fill_n(vec2.begin(), 10, 0);

}
