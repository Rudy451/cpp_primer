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

};

class Prot_Derv: protected Base {

	public:
		Prot_Derv(int val_one, char val_two): Base(val_one, val_two) {}
		int f(){return prot_num;}

};

class Priv_Derv: private Base {
	
	public:
		Priv_Derv(int val_one, char val_two): Base(val_one, val_two) {}
		int f(){return prot_num;}

};

class Derived_from_Pub: public Pub_Derv{

	public:
		Derived_from_Pub(int val_one, int val_two): Pub_Derv(val_one, val_two) {}

};

int main(){

	auto d1 = Pub_Derv(1, 'a');
	auto d2 = Prot_Derv(2, 'b');
	auto d3 = Priv_Derv(3, 'c');
	auto d4 = Derived_from_Pub(4, 'd');

	Base *p = &d1;
	//p = &d2;
	//p = &d3;
	p = &d4; 

}
