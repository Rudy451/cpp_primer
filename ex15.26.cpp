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

	// Constructor
	Discount(int val, string val2): Quote(val, val2) {cout << "Derived Constructor" << endl;}

	// Copy Constructor
	Discount(const Discount& ex): Quote::Quote(ex) {cout << "Derived Copy Constructor" << endl;}

	// Copy Assignment Operator
	Discount operator=(const Discount& ex){Quote::operator=(ex); cout << "Derived Copy Assignment Operator" << endl;} 

	// Destructor	
	~Discount(){cout << "Derived Destructor" << endl;}
	
	// Net Price
	double net_price(size_t num) const {auto temp = price * num; return temp - (temp * (disc_rt / 100));}
private:
	double disc_rt = 25;
};

double print_total(ostream &os, const Quote &item){

	os << "Item Total: " << item.net_price(4) << endl;

}

int main(){

	// Base Constructor	
	Quote Ex(12, "Almonds");

	// Base Constructor, Derived Constructor
	Discount Ex1(12, "Other");

	// Base Copy Constructor, Derived Copy Constructor
	Discount Ex2(Ex1);
	
	// Base Copy Constructor
	Quote Ex3(Ex);

	// Base Copy Constructor
	Quote Ex4(Ex1);

	return 0;

}
