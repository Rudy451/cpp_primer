#include <iostream>
#include <vector>

using std::vector;

class Default{
public:
	Default(int one);
private:
	int two;
};

class c{
public:
	Default my_memb(int three);
private:
	int three;
};

int main(){

	vector<c> vec(10);

}
