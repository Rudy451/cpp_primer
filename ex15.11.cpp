#include <iostream>

using namespace std;

class Quote{
public:
	// Default Constructor
	Quote() = default;
	
	// Constructor
	Quote(int val): price(val){}
	
	// Destructor
	virtual ~Quote(){};

	// Net Price
	virtual double net_price(size_t num) const {return num * price;}

	// Set Price
	void set_price(int val){price = val;};

	// Debug
	virtual void debug(){cout << this->price << endl;}

private:
	string product;
protected:
	double price = 0;

};

class Discount : public Quote{
public:
	Discount(int val, int rt): Quote(val), disc_rt(rt) {}
	// Net Price
	double net_price(size_t num) const {auto temp = price * num; return temp - (temp * (disc_rt / 100));}
	// debug
	void debug(){cout << this->price << " " << this->disc_rt << endl;}
private:
	double disc_rt;
};

double print_total(ostream &os, const Quote &item){

	os << "Item Total: " << item.net_price(4) << endl;

}

int main(){
	
	Quote Ex(12);
	Discount Ex1(13, 25);
	/*
	print_total(cout, Ex);
	print_total(cout, Ex1);
	*/
	Ex.debug();
	Ex1.debug();
	return 0;

}
