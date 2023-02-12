#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;

vector<int> *in_vec(vector<int> *vec);
void out_vec(vector<int> *vec);

vector<int> *ret_vec(){

	vector<int> *vec = (new vector<int>);
	in_vec(vec);

}

vector<int> *in_vec(vector<int> *vec){

	int val;
	while(cin >> val){
		vec->push_back(val);
	}

	out_vec(vec);

}

void out_vec(vector<int> *vec){

	for(auto i = vec->begin(); i != vec->end(); ++i){
		cout << *i << " ";
	}
	cout << endl;

	delete vec;

}

int main(){

	ret_vec();

}
