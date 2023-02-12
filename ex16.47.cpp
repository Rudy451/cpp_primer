#include <iostream>
#include <utility>

using namespace std;

template<typename T1, typename T2> void concat_ftn(T1 f(T1, T2), T1 first, T2 second){

		
	f(forward<T1>(first), forward<T2>(second));
	cout << " ";
	f(forward<T2>(second), forward<T1>(first));
	cout << endl;
	
}

template<typename t1, typename t2> auto concat_args(t1 arg1, t2 arg2) -> typename remove_reference<decltype(arg1)>::type {

	cout << arg1 << " " << arg2;
	return arg1;
	
}

int main(){

	auto arg1 = "Let's";
	concat_ftn(concat_args, arg1, "Go");

}
