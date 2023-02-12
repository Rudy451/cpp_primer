#include <iostream>
#include <string>
#include <vector>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	int num;
	vector<int> num_list;

	while(cin >> num){
		num_list.push_back(num);
	}

	for(int num_it : num_list){
		cout << num_it << endl;
	}

	return 0;	
}
