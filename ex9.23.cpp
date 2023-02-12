#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

int main(){
	
	vector<int> c = {1};

	if(!c.empty()){
		auto val = c.begin();
		auto val2 = c.front();
		auto val3 = *(--c.end());
		auto val4 = c.back();
		
		cout << *(val) << val2 << val3 << val4 << endl;
	}

}

