#include <iostream>
#include <vector>
#include <memory>

using std::cin; using std::cout; using std::endl; using std::vector; using std::shared_ptr; using std::make_shared;

void in_vec(vector<shared_ptr<int>> &vec);
void out_vec(vector<shared_ptr<int>> &vec);

void ret_vec(){

	vector<shared_ptr<int>> vec;
	in_vec(vec);

}

void in_vec(vector<shared_ptr<int>> &vec){

	int val;
	while(cin >> val){
		vec.push_back(make_shared<int>(val));
	}
	
	out_vec(vec);
	
}

void out_vec(vector<shared_ptr<int>> &vec){

	for(auto i = vec.begin(); i != vec.end(); ++i){
		cout << **i << " ";
	}

	cout << endl;

}

int main(){

	ret_vec();

}
