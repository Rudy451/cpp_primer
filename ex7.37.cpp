#include <iostream>

using std::string; using std::cin; using std::cout; using std::endl; using std::istream;

class Sales_data{
public:
	// Defines the default constructor as well as one that takes a string argument
	Sales_data(string s = ""): bookNo(s) {}
	
	// Remaining constructors unchanged
	Sales_data(string s, unsigned cnt, double rev): bookNo(s), units_sold(cnt), revenue(rev*cnt){}
	Sales_data(istream &is) {read(is, *this);}

	string isbn() const {return bookNo;}

        Sales_data& combine(const Sales_data &book);

        istream &read(istream &is, Sales_data &item)
        {
                double price = 0;
                is >> item.bookNo >> item.units_sold >> price;
                item.revenue = price * item.units_sold;
                return is;
        }
private:
        double avg_price() const;
        string bookNo = "12345";
        unsigned units_sold = 0;
        double revenue = 0.0;
};


int main(){

	Sales_data next;
	Sales_data last("9-999-99999-9");

	cout << next.isbn() << endl;
	cout << last.isbn() << endl;

	return 0;
}
