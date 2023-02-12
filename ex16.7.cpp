#include <iostream>
#include <array>

using namespace std;

template<typename T> size_t constexprex(T Arr){

	return sizeof(Arr) / sizeof(Arr[0]);

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
	Arr[8] = "man";

	cout << constexprex(Arr) << endl;


}
