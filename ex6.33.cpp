#include <iostream>
#include <vector>

using std::cout; using std::vector; using std::endl;

vector<int> num_list{1, 2, 3, 4, 5, 6, 7, 8};

int num_index(int index){

	if(index != num_list.size()){
		cout << num_list[index] << endl;
		num_index(++index);
	} 

	return 0;
}

int main(){
	int i = 0;		
	vector<int> num_list{1, 2, 3, 4, 5};
	num_index(i);

}
