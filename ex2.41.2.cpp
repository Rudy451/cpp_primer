#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Sales_data.h"

int i = 1;
Sales_data item;
std::vector<std::string> BOOK;
std::string ask = "Please enter Book ID";
std::string zero = "0";

int main()
{
	std::cout << ask << std::endl;
	while(std::cin >> item.book_id){
		BOOK.resize(i, item.book_id);
		i += 1;
		std::cout << ask << std::endl;;
	}	

        for(int j = 0; j < BOOK.size(); ++j){
                if(BOOK[j] != zero){
                        int count = 0;
                        for(int k = 0; k < BOOK.size(); ++k){
                                if(BOOK[j] == BOOK[k]){
                                        count += 1;
                                }
                        }
                        std::cout << "ISBN #" << BOOK[j] << " count:" << count << std::endl;
                        std::string label = BOOK[j];
                        std::replace(BOOK.begin(), BOOK.end(), label, zero);
                }

        }
	
	return 0;
}


