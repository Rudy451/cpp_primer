#include <iostream>

using namespace std;

template<typename T, typename... Args> void foo(const T &t, const Args&... rest){cout << sizeof...(Args) << endl; cout << sizeof...(rest) << endl;}

int main(){

	foo("Hi", "My", "Favorite", "Number", "is ", 2);

}
