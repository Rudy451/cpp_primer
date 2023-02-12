#include <iostream>

struct Y;

struct X{

 	int first_member;
	int second_member;

	class Y *ex_stuff;
	
};

struct Y{	
	int first_y;

	class X;
};

int main(){
	
	return 0;
}
