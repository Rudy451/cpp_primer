#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector; using std::distance;

vector<int> temp = {2, 4, 6, 8, 10};

auto first = temp.begin();
auto last = temp.end();

int temp_ftn(vector<int>::iterator first, vector<int>::iterator second, int target){

	while(first != last){
		if(*(first) == target){
			return distance(temp.begin(), first);
		}
		++first;
	}

	return -1;
}

int main(){

	int target = 2;
	cout << temp_ftn(first, last, target) << endl;	

}
