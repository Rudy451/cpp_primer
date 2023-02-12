#include <iostream>
#include <string>
#include <array>

using namespace std;

template<typename T, size_t t> T *beg(array<T, t> first){

	return &first[0];

}

template<typename T, size_t t> T *last(array<T, t> lst){

	return &lst[0] + t;

}

template<typename T> void print(T &Arr){

	for(auto i = 0; i < Arr.size(); ++i){
			cout << Arr[i] << endl;
	}

}


int main(){

	array<string, 8> sent;
	sent[0] = "I";
	sent[1] = "like";
	sent[2] = "to";
	sent[3] = "play";
	sent[4] = "games";
	sent[5] = "of";
	sent[6] = "all";
	sent[7] = "kinds";

	cout << *(beg(sent)) << endl;
	cout << *(last(sent) - 1) << endl;

	array<int, 4> num;
	num[0] = 1;
	num[1] = 2;
	num[2] = 3;
	num[3] = 4;
	
	cout << *(beg(num)) << endl;
	cout << *(last(num) - 1) << endl;
	

}
