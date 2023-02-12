#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T> int vec_ct(vector<T> vec, T val){

	return count(vec.begin(), vec.end(), val);

}

template<> int vec_ct(vector<const char*> vec, const char* val){

	cout << "I'm Special" << endl;
	return count(vec.begin(), vec.end(), val);

}

int main(){

	vector<int> ex1 = {1, 2, 1, 3, 1, 4, 1, 5, 6, 1};
	cout << vec_ct<int>(ex1, 1) << endl;
	vector<string> ex2 = {"I", "like", "stuff", "like", "sports"};
	cout << vec_ct<string>(ex2, "like") << endl;
	vector<const char*> ex3 = {"I", "want", "to", "win", "and", "to", "be", "happy"};
	cout << vec_ct(ex3, "to") << endl;

}
