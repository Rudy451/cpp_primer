#include <iostream>
#include <deque>
#include <list>

using std::cout; using std::endl; using std::deque; using std::list;

int main(){

	list<int> temp_list = {1, 2, 3, 4, 5, 6};

	deque<int> temp_deque_one;
	deque<int> temp_deque_two;

	for(list<int>::iterator i = temp_list.begin(); i != temp_list.end(); ++i){
		if(*(i) % 2 == 0){
			temp_deque_one.push_back(*(i));
		} else {
			temp_deque_two.push_back(*(i));
		}
	}

	cout << "First Size: " << temp_deque_one.size() << " and Second Size: " << temp_deque_two.size() << endl;

}
