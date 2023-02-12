#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct X{

	X() {cout << "X()" << endl;}
	X(const X&) {cout << "X(const X&)" << endl;}
	X& operator=(const X& orig){
		cout << "Copying..." << endl;;
		return *this;
	};
	~X(){cout << "Buh Bye" << endl;}
};

void This_Is_Fun(){

	X first;
	X second;
	second = first;
	X third(second);
	auto fourth = new X;
	delete fourth;
	vector<X> fifth;
	fifth.push_back(first);
	X &sixth = first;
	X seventh(sixth);

}

int main(){

	This_Is_Fun();

}
