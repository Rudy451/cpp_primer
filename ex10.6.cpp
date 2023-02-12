#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

int main(){

	vector<int> targ_list(10, 0);
	
	fill_n(targ_list.begin(), targ_list.size(), 1);

	for(size_t i = 0; i < targ_list.size(); ++i){
		cout << targ_list[i] << endl;
	}

	return 0;

}
