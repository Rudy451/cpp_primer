#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::vector; using std::endl;

int num;
vector<int> num_list;

int num2;
vector<int> num_list2;

int main()
{

	// Idiosyncratic loops
	while(cin >> num){
		num_list.push_back(num);
	}
	
	for(int i = 0; i < num_list.size(); ++i){
		cout << num_list[i] << endl;
	}

	// alternative loops
	for(num2; cin >> num2;){
		num_list2.push_back(num2);	
	}

	int i = 0;

	while(i < num_list2.size()){
		cout << num_list2[i] << endl;
		++i;
	}
}



