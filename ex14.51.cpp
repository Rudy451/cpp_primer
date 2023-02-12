#include <iostream>

using namespace std;

struct LongDouble{
	
	LongDouble(double = 0.0) {}
	operator double() {}
	operator float() {}

};

void calc(int){cout << "int" << endl;}
void calc(LongDouble){cout << "LongDouble" << endl;}

int main(){

	double dval;
	calc(dval);

}
