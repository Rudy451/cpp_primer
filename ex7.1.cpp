#include <iostream>
#include <string>
#include "ex2.4.h"

using std::string; using std::cin; using std::cout; using std::endl; using std::cerr; using std::istream;

int main()
{

	cout << "Please enter first item..." << endl;

	Sales_data total(cin);

	string response = "yes";

	while(response == "yes"){

		Sales_data trans(cin);

		if(trans.isbn() == total.isbn()){
			total.combine(trans);
		} else {
			print(total);
			total = trans; 
			cout << "Another Purchase?" << endl;
			cin >> response;
		}
	}
}	
