#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <array>

using std::cout; using std::endl; using std::vector; using std::list; using std::deque; using std::front_inserter; using std::back_inserter; using std::copy; using namespace std::placeholders;

int main(){

	vector<int> first_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> sec_list;
	vector<int> third_vec;
	auto it = third_vec.begin();
	deque<int> fourth_deque;

	copy(first_vec.begin(), first_vec.end(), back_inserter(sec_list));
	copy(first_vec.begin(), first_vec.end(), inserter(third_vec, it));
	copy(first_vec.begin(), first_vec.end(), front_inserter(fourth_deque));

	for(auto i = sec_list.begin(); i != sec_list.end(); ++i){
		cout << *i << " ";
	}
	cout << endl;	

	for(auto i = third_vec.begin(); i != third_vec.end(); ++i){
		cout << *i << " ";
	}
	cout << endl;	
	

	for(auto i = fourth_deque.begin(); i < fourth_deque.end(); ++i){
		cout << *i << " ";
	}
	cout << endl;	
}
