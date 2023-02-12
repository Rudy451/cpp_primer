#include <iostream>
#include <array>

using namespace std;

template<typename T> void print(T &Arr){

	for(auto i = 0; i < Arr.size(); ++i){
			cout << Arr[i] << endl;
	}

}

int main(){

	array<string, 8> Arr;
	Arr[0] = "I";
	Arr[1] = "like";
	Arr[2] = "to";
	Arr[3] = "play";
	Arr[4] = "games";
	Arr[5] = "of";
	Arr[6] = "all";
	Arr[7] = "kinds";

	print(Arr);

}
