#include <iostream>
#include <string>
#include <deque>

using std::cin; using std::cout; using std::endl; using std::string; using std::deque;

int main(){

	string temp;
	deque<string> temp_deque;

	while(cin >> temp){
		temp_deque.push_back(temp);
	}

	deque<string>::iterator temp_iter;

	for(temp_iter = temp_deque.begin(); temp_iter != temp_deque.end(); ++temp_iter){
		cout << *(temp_iter) << endl;
	}
	
	return 0;

}
