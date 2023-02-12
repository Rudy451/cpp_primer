#include <iostream>
#include <list>
#include <forward_list>

using std::cout; using std::endl; using std::list; using std::forward_list;

int main(){

	list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = vi.begin();

	while(iter != vi.end()){
		if(*iter % 2){
			vi.insert(iter, *iter);
			++iter;
		} else {
			iter = vi.erase(iter);
		}
	}

	forward_list<int> vi2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto prev = vi2.before_begin();
	auto curr = vi2.begin();

	while(curr != vi2.end()){
		if(*curr % 2){
			prev = vi2.insert_after(curr, *curr);
			curr = prev;
			++curr;
		} else {
			curr = vi2.erase_after(prev);
		}
	}


	for(auto i = vi2.begin(); i != vi2.end(); ++i){
		cout << *i << endl;
	}

}
