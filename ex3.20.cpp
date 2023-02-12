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

	for(int i = 0; i < num_list.size(); i=i+2){
		cout << num_list[i] << ", " << num_list[i+1] << endl;	
	}

	for(int i = 0; i < (num_list.size() / 2); ++i){
                auto temp_sum = num_list[i] + num_list[(num_list.size()-1)-i];	
		cout << temp_sum << endl;
        }
}
