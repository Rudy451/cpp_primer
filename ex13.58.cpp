#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo{
public:
Foo() = default;

Foo(initializer_list<int> il){

	for(auto i = il.begin(); i != il.end(); ++i){
		this->data.push_back(*i);
	}
	cout << data.size() << endl;

}

Foo(const Foo& orig): data(orig.data) {cout << this->data.size() << endl;}

Foo sorted() &&;
Foo sorted() const &;

private:
vector<int> data;

};

Foo Foo::sorted() && {

	sort(this->data.begin(), this->data.end());
	return *this;

}
/*
Foo Foo::sorted() const & {

	Foo ret(*this);
	return ret.sorted();

}
*/
Foo Foo::sorted() const & {

	return Foo(*this).sorted();

}

int main(){

	Foo ex({6, 3, 7, 1});
	ex.sorted();
	return 0;

}
