#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;

vector<int> temp = {2, 4, 6, 8, 10};

auto first = temp.begin();
auto last = temp.end();

bool temp_ftn(vector<int>::iterator first, vector<int>::iterator second, int target){

	while(first != last){
		if(*(first) == target){
			cout << "Success!" << endl;
			return 1;
		}
		++first;
	}

	cout << "Fail" << endl;
	return 0;
}

int main(){

	int target = 8;
	temp_ftn(first, last, target);	

}
