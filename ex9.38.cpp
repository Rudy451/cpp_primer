#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

int main(){

	vector<int> ex_vec(10, 1);		
	auto i = 0;

	while(i < 11){
		if(i > 9){
			ex_vec.push_back(1);
		}
		
		cout << "Element: " << ex_vec[i] << endl;
		cout << "Capacity: " << ex_vec.capacity() << endl;
		cout << "Size: " << ex_vec.size() << endl;

		++i;
	}


}
