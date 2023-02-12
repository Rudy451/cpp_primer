#include <iostream>
#include <string>
#include "ex2.4.h"

using std::cin; using std::cout; using std::endl; using std::istream; using std::string;

int main(){

	string name;
	unsigned units;
	double price;
	

	cout << "Please enter the book name, number of copies purchased, & price:" << endl;

	cin >> name >> units >> price;
	
	Sales_data New_Book(name, units, price);
	cout << New_Book.isbn() << ": " << New_Book.avg_price() << endl;

	return 0;

}
