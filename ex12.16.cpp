#include <iostream>
#include <memory>

using std::cout; using std::endl; using std::unique_ptr;

int main(){

	unique_ptr<int> one(new int(1));
	// First
	unique_ptr<int> two(one);

	// Second
	one.release();

	// Third
	unique_ptr<int> three(new int(3));
	one.reset(three);

}
