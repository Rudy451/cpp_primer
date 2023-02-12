#include <iostream>

using namespace std;

struct DebugDelete{

	template<typename T> DebugDelete(T *p, ostream &os = cout){os << "Deleting Pointer...." << endl; delete p;}

};

int main(){

	int *a = new int();
	DebugDelete b(a);
	string *c = new string();
	DebugDelete d(c);

}
