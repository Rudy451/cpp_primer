#include <iostream>

using namespace std;

class Base{

public:
	virtual int fcn(){cout << "Base" << endl; return 1;};
};

class D1 : public Base {
public:
	using Base::fcn;
	virtual int fcn(int){cout << "Derived" << endl; return 2;};
	virtual void f2(){cout << "YAY" << endl;}

};

class D2 : public D1 {

public:
	using D1::fcn;
	using D1::f2;

};

int main(){

	Base bobj; D1 d1obj; D2 d2obj;
	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	cout << bp1->fcn() << endl;
	cout << bp2->fcn() << endl;
	cout << bp3->fcn() << endl;
	
	D1 *d1p = &d1obj; D2 *d2p = &d2obj;
	//bp2->f2();
	d1p->f2();
	d2p->f2();

	Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
	//cout << p1->fcn(42) << endl;
	cout << p2->fcn(42) << endl;
	cout << p3->fcn(42) << endl;
}
