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

	// Return Price
	double get_price(){return price;}

private:
	string product;
protected:
	double price = 0;

};

class Discount : public Quote{
public:
	// Net Price
	double net_price(size_t num) const {auto temp = price * num; return temp - (temp * (disc_rt / 100));}
private:
	double disc_rt = 25;
};

double print_total(ostream &os, const Quote &item){

	os << "Item Total: " << item.net_price(4) << endl;

}

int main(){
	
	Quote Ex;
	Discount Ex1;
	Ex.set_price(12);
	Ex1.set_price(12);
	print_total(cout, Ex);
	print_total(cout, Ex1);
	return 0;

}
