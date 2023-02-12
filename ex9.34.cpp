#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

int main(){

	vector<int> vi = {5, 10};
	auto iter = vi.begin();
	
	while(iter != vi.end()){
		if(*iter % 2){
			iter = vi.insert(iter, *iter);
			++iter;
		}
		++iter;
	}
	
	for(auto i = vi.begin(); i != vi.end(); ++i){
		cout << *i << endl;
	} 
}
