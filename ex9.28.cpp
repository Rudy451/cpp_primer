#include <iostream>
#include <forward_list>
#include <string>

using std::cout; using std::endl; using std::forward_list; using std::string;

forward_list<string> fwd_str_list = {"Clemson", "Oklahoma"};

void str_ins_ftn(forward_list<string> &fwd_str_list, string one="", string two=""){

	auto prev = fwd_str_list.before_begin();
	auto curr = prev;
	bool broke = false;

	while(curr != fwd_str_list.end()){
		if(curr != fwd_str_list.before_begin() && (*curr == one)){
			prev = fwd_str_list.insert_after(curr, two);
			broke = true;
			break;
		} else {  
			if(prev != curr){++prev;}
			++curr;
		}
	} 
	
	if(broke == false){fwd_str_list.insert_after(prev, two);}
	
}

int main(){

	str_ins_ftn(fwd_str_list, "Georgia", "Alabama");

	for(auto i = fwd_str_list.begin(); i != fwd_str_list.end(); ++i){
		cout << *i << endl;
	}

}
