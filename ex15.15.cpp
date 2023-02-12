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
	Discount(int val, int rt): Quote(val), disc_rt(rt) {}
	// Net Price
	double net_price(size_t num) const = 0;
protected:
	double disc_rt;
};

class Bulk_Discount : public Discount{
public:
	Bulk_Discount(int val, int rt): Discount(val, rt) {}
	// Net Price
	double net_price(size_t num) const;

};

double Bulk_Discount::net_price(size_t num) const {
	auto temp = price * num; 
	if(num < 8){
		return temp - (temp * (disc_rt / 100));
	} else {
		return temp;
	}
}

double print_total(ostream &os, const Quote &item){

	os << "Item Total: " << item.net_price(7) << endl;

}
	
int main(){
	
	Quote Ex(5);
	Bulk_Discount Ex1(5, 25);
	print_total(cout, Ex);
	print_total(cout, Ex1);
	return 0;

}
