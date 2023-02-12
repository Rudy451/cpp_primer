#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Basket;

class Quote{

friend Basket;

public:
	// Default Constructor
	Quote() = default;
	
	// Constructor
	Quote(double val, int val2, string val3): price(val), qty(val2), product(val3) {}

	// Copy Constructor
	Quote(const Quote& ex): product(ex.product), price(ex.price) {}

	// Copy Assignment Operator
	Quote operator=(const Quote& ex){product = ex.product; price = ex.price;} 
	
	// Destructor
	virtual ~Quote(){}

	// Clone
	virtual shared_ptr<Quote> clone() const & {return make_shared<Quote>(this->price, this->qty, this->product);}

	// Net Price
	virtual double net_price() const {return price * qty;}

	// Set Price
	void set_price(int val){price = val;};

	// Return Price
	double get_price(){return price;}

protected:
	string product;
	double price = 0;
	int qty = 0;
};

class Discount : public Quote{

friend Basket;

public:

	// Constructor
	Discount(double val, int val2, string val3, double val4 = 0): Quote(val, val2, val3), disc_rt(val4){}

	// Copy Constructor
	Discount(const Discount& ex): Quote::Quote(ex){}

	// Copy Assignment Operator
	Discount operator=(const Discount& ex){} 

	// Destructor	
	~Discount(){}

	// Clone
	shared_ptr<Quote> clone() const & {return make_shared<Discount>(this->price, this->qty, this->product, this->disc_rt);}

	// Set Rate
	void set_rate(double val) {disc_rt = val;} 
	
	// Net Price
	double net_price() const {auto temp = price * qty; return temp - (temp * (disc_rt / 100));}
private:
	double disc_rt = 25;
};

double print_total(ostream &os, const Quote &item){

	os << "Item Total: " << item.net_price() << endl;
	return item.net_price();

}

class Basket{

public:
	void add_item(const Quote &sale){trans_list.push_back(sale.clone());};
	double trans_total();
	void clear_total(){total = 0;}

private:	
	double total = 0;
	vector<shared_ptr<Quote>> trans_list;

};

double Basket::trans_total(){

	for(auto i = 0; i < trans_list.size(); ++i){
		total += print_total(cout, *(trans_list[i]));
	}

	return total;
}

int main(){

	Quote P1(2.99, 2, "Soap");
	Discount P2(2.99, 2, "Powder", 25);
	Quote P3(3.99, 4, "Soda");
	Basket Bs;
	Bs.add_item(P1);
	Bs.add_item(P2);
	Bs.add_item(P3);
	Bs.trans_total();
	return 0;

}
