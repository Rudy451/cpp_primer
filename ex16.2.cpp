#include <iostream>

using namespace std;

template<typename T> bool compare(const T &one, const T &two){

	return (two < one) ? 1 : (one < two) ? 0 : -1;

}

int main(){

	cout << compare(1, 0) << endl;


}
