#include <iostream>
#include <string>
#include "ex2.4.h"

using std::cin; using std::cout; using std::endl; using std::istream; using std::string;

int main(){

	Sales_data New_Book;

	cout << New_Book.isbn() << ": " << New_Book.avg_price() << endl;

	return 0;

}
