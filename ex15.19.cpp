#include <iostream>

using namespace std;

class Base{

	public:
		Base() = default;
		Base(int val_one, char val_two): prot_num(val_one), prot_char(val_two) {}
		int prot_ftn(){return prot_num;}
		int priv_ftn(){return priv_num;}
	protected:
		int prot_num;
		int prot_char;
	private:
		int priv_num = 'g';
		char priv_char = 100;

};

class Pub_Derv: public Base {
	public:
		Pub_Derv(int val_one, char val_two): Base(val_one, val_two) {}
		int f(){return prot_num;}
		int memfcn(Base &b){b = *this;}

};

class Prot_Derv: protected Base {

	public:
		Prot_Derv(int val_one, char val_two): Base(val_one, val_two) {}
		int f(){return prot_num;}
		int memfcn(Base &b){b = *this;}

};

class Priv_Derv: private Base {
	
	public:
		Priv_Derv(int val_one, char val_two): Base(val_one, val_two) {}
		int f(){return prot_num;}
		int memfcn(Base &b){b = *this;}

};

class Derived_from_Pub: public Pub_Derv{

	public:
		Derived_from_Pub(int val_one, int val_two): Pub_Derv(val_one, val_two) {}
		int memfcn(Base &b){b = *this;}
};

class Derived_from_Prot: protected Prot_Derv{

	public:
		Derived_from_Prot(int val_one, int val_two): Prot_Derv(val_one, val_two) {}
		int memfcn(Base &b){b = *this;}
};

class Derived_from_Priv: private Priv_Derv{

	public:
		Derived_from_Priv(int val_one, int val_two): Priv_Derv(val_one, val_two) {}
		int memfcn(Base &b){b = *this;}
};

int main(){

	auto d1 = Pub_Derv(1, 'a');
	auto d2 = Prot_Derv(2, 'b');
	auto d3 = Priv_Derv(3, 'c');
	auto d4 = Derived_from_Pub(4, 'd');
	auto d5 = Derived_from_Prot(5, 'e');
	auto d6 = Derived_from_Priv(6, 'f');


	Base p;
	Base &p1 = p;
	d1.memfcn(p1);
	d2.memfcn(p1);
	d3.memfcn(p1);
	d4.memfcn(p1);
	d5.memfcn(p1);
//	d6.memfcn(p1);
	//p = &d2;
	//p = &d3;
//	p = &d4; 

}
