#include <iostream>

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

	c C;

}
