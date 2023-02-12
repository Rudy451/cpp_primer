#include <iostream>

using namespace std;

struct numbered{

	numbered(){mysn = (rand() % 100) + (rand() % 20) + (rand() % 3);}
	int mysn;

};

void f(numbered s){cout << s.mysn << endl;}	

int main(){

	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;

}
