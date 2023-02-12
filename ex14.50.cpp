#include <iostream>

using namespace std;

struct LongDouble{
	
	LongDouble(double = 0.0) {}
	operator double() {}
	operator float() {}

};

int main(){

	LongDouble lft;
	//int ex1 = lft;
	long ex2 = lft;

}
