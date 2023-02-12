#include <iostream>
#include <vector>

using std::vector;

class Default{
public:
	Default(int one);
private:
	int two;
};

int main(){

	// Won't compile because there is no default constructor.
	// The compiler will get confused.
	vector<Default> vec(10);

}
