#include <iostream>

using std::string; using std::cin; using std::cout; using std::endl; using std::istream;

class Sales_data{
public:

	Sales_data(string s, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(cnt * price) {}

	Sales_data(): Sales_data("Sorceror's_Stone", 0, 0) {cout << "Default Approach!" << endl;}
	Sales_data(string s): Sales_data(s, 0, 0) {cout << "String Approach!" << endl;}
	Sales_data(string s, unsigned cnt): Sales_data(s, cnt, 1) {cout << "String & Count Approach!" << endl;}

	string isbn(){return bookNo;}
private:
        double avg_price() const;
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};


int main(){

	Sales_data first;
	Sales_data second("Chamber_of_Secrets!");
	Sales_data third("Prisoner_of_Azkaban!", 2);

	cout << first.isbn() << endl;
	cout << second.isbn() << endl;
	cout << third.isbn() << endl;
	
	return 0;
}
