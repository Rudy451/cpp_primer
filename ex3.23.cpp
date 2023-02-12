#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	int num;
	vector<int> num_list(10);

	
	for(auto i = 0; i < num_list.size(); ++i){
		cin >> num;
		num_list[i] = num;
	}

	for(auto iter = num_list.begin(); iter != num_list.end(); ++iter){
		*iter = 2 * *iter;
		cout << *iter << ", ";
	}
   
	cout << endl;

	return 0;	
}
