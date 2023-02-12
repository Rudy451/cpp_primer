#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Sales_data.h"

using std::cin; using std::cout; using std::endl; using std::vector; using std::string;

int i = 1;
Sales_data item;
vector<string> BOOK;
string ask = "Please enter Book ID";
string zero = "0";

int main()
{
	cout << ask << endl;
	while(cin >> item.book_id){
		BOOK.resize(i, item.book_id);
		i += 1;
		cout << ask << endl;;
	}	

        for(int j = 0; j < BOOK.size(); ++j){
                if(BOOK[j] != zero){
                        int count = 0;
                        for(int k = 0; k < BOOK.size(); ++k){
                                if(BOOK[j] == BOOK[k]){
                                        count += 1;
                                }
                        }
                        cout << "ISBN #" << BOOK[j] << " count:" << count << endl;
                        string label = BOOK[j];
                        replace(BOOK.begin(), BOOK.end(), label, zero);
                }

        }
	
	return 0;
}


