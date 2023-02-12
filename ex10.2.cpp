#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::cout; using std::endl; using std::list; using std::count; using std::string;

list<string> count_lst = {"Jones", "Smith", "Jones"};

int main(){

	cout << count(count_lst.begin(), count_lst.end(), "Jones") << endl;

}
