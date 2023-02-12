#include <iostream>
#include <forward_list>

using std::cout; using std::endl; using std::forward_list;

int main(){

	forward_list<int> temp_fwd = {1, 2, 3, 4};	

	auto prev = temp_fwd.before_begin(); 
	auto curr = prev;

	while(curr != temp_fwd.end()){
		if(*(curr) % 2){
			curr = temp_fwd.erase_after(prev);
		} else {
			prev = curr;
			++curr;
		}
	}	

	for(auto iter = temp_fwd.begin(); iter != temp_fwd.end(); ++iter){
		cout << *iter << endl;
	}

	return 0;
}
