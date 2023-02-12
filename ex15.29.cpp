#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Quote{
public:
	// Default Constructor
	Quote() = default;
	
	// Constructor
	Quote(int val, string val2): price(val), product(val2) {}

	// Copy Constructor
	Quote(const Quote& ex): product(ex.product), price(ex.price) {}

	// Copy Assignment Operator
	Quote operator=(const Quote& ex){product = ex.product; price = ex.price;} 
	
	// Destructor
	virtual ~Quote(){}

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
	Discount(int val, string val2, double val3): Quote(val, val2), disc_rt(val3){}

	// Copy Constructor
	Discount(const Discount& ex): Quote::Quote(ex){}

	// Copy Assignment Operator
	Discount operator=(const Discount& ex){} 

	// Destructor	
	~Discount(){}
	
	// Net Price
	double net_price(size_t num) const {auto temp = price * num; return temp - (temp * (disc_rt / 100));}
private:
	double disc_rt = 25;
};

double print_total(ostream &os, const Quote &item){

	os << "Item Total: " << item.net_price(4) << endl;
	return item.net_price(4);

}

int main(){

	vector<shared_ptr<Quote>> ex_vec;
	ex_vec.push_back(make_shared<Quote>(1, "first"));
	ex_vec.push_back(make_shared<Discount>(2, "second", 26));
	ex_vec.push_back(make_shared<Quote>(3, "third"));

	for(auto i = 0; i < ex_vec.size(); ++i){
		print_total(cout, *(ex_vec[i]));
	}
	
	return 0;

}
