#include <iostream>

using namespace std;

class Quote{
public:
	// Default Constructor
	Quote() = default;
	
	// Constructor
	Quote(int val, string val2): price(val), product(val2) {cout << "Base Constuctor" << endl;}

	// Copy Constructor
	Quote(const Quote& ex): product(ex.product), price(ex.price) {cout << "Base Copy Constructor" << endl;}

	// Copy Assignment Operator
	Quote operator=(const Quote& ex){product = ex.product; price = ex.price; cout << "Base Copy Assignment Operator" << endl;} 
	
	// Destructor
	virtual ~Quote(){cout << "Base Destructor" << endl;}

	// Net Price
	virtual double net_price(size_t num) const {return num * price;}

	// Set Price
	void set_price(int val){price = val;};

	// Return Price
	double get_price(){return price;}

protected:
	string product;
	double price = 0;

};

class Discount : public Quote{
public:

	// Inherit Quote Constructors	
	using Quote::Quote;

	// Using Base Class Constructor
	Discount(int val, string val2): Quote(val, val2) {}

	// Net Price
	double net_price(size_t num) const {auto temp = price * num; return temp - (temp * (disc_rt / 100));}
private:
	double disc_rt = 25;
};

double print_total(ostream &os, const Quote &item){

	os << "Item Total: " << item.net_price(4) << endl;

}

int main(){

	Discount ex(12, "Burrito");
	print_total(cout, ex);
	
}
