#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

vector<int> iv{1, 2, 3};

void iter_ftn(vector<int> &iv, int target){

	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + (iv.size() / 2);

	while(iter != mid){
		if(*iter == target){
			iv.insert(iter, 2 * target);
			++iter;
		}
	}	
}

int main(){

	iter_ftn(iv, 1);

}

