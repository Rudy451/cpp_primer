#include <string>

using std::string; using std::cin; using std::cout; using std::endl; using std::istream; using std::ostream;

class Sales_data{

friend Sales_data add(const Sales_data&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&, const Sales_data&);

public:
	Sales_data() = default;
	Sales_data(const string &s): bookNo(s) {};
	Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {}
	Sales_data(istream &is){read(is, *this);};	
	string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data &book);
	
private:
	double avg_price() const;
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


Sales_data& Sales_data::combine(const Sales_data &book){
	units_sold += book.units_sold;
	revenue += book.revenue;
	return *this;
}

inline double Sales_data::avg_price() const{
	return (units_sold ? revenue / units_sold : 0);
}

Sales_data add(const Sales_data book1, const Sales_data book2){

	Sales_data temp = book1;
	temp.combine(book2);
	return temp;
}


ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}


istream& read(istream &is, Sales_data &item){
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

