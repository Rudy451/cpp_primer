#include <iostream>
#include <fstream>
#include "ex2.4.h"

using std::cin; using std::cout; using std::endl; using std::cerr; using std::ifstream; using std::ofstream;

int main(int argc, char *argv[]){

	ifstream ex(argv[1]);
	ofstream ex2(argv[2]);
	Sales_data total, trans;

        if(read(ex, total)){
		while(read(ex, trans)){
			if(total.isbn() == trans.isbn()){
				total.combine(trans);
			} else {
				print(ex2, total) << endl; 
				total = trans;
			}
		}
		
		print(ex2, total) << endl;
	} else {
		cerr << "No Data?!" << endl;
	}

	ex.close();
	ex2.close();

}
