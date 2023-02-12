#include <iostream>
#include <string>
#include <list>

using std::cin; using std::cout; using std::endl; using std::string; using std::list;

int main(){

	string temp;
	list<string> temp_list;

	while(cin >> temp){
		temp_list.emplace_back(temp);
	}

	list<string>::iterator temp_iter;

	for(temp_iter = temp_list.begin(); temp_iter != temp_list.end(); ++temp_iter){
		cout << *(temp_iter) << endl;
	}
	
	return 0;

}
