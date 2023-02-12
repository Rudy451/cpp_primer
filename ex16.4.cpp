#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T, typename t> T fake_find(const T& start, const T& end, const t& val){

	for(auto i = start; i != end; ++i){
		if(*i == val){return i;}
	}
	
	return end;

}

int main(){

	vector<int> one = {1, 2, 3};
	list<string> two = {"What's", "your", "name"};
	cout << *(fake_find(one.begin(), one.end(), 5)) << endl;
	cout << *(fake_find(two.begin(), two.end(), "name")) << endl;


}
