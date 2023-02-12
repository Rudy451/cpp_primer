#include <iostream>
#include <memory>
#include <type_traits>

using namespace std;
static int counter = 0;

//pg. 871
template<typename T, class... Args> auto make_share(Args&&... args) -> typename add_pointer<decltype(args)...>::type {

	++counter;
	return new T(forward<Args>(args)...);

}

int main(){

	auto p = make_share<int>(1);
	cout << counter << endl;

}
