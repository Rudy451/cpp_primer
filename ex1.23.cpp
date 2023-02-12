#include <iostream>
#include <algorithm>
#include "Sales_item.h"
#include <vector>

int i = 1;
Sales_item item;
std::vector<std::string> BOOK;
std::string zero = "0";

int main(){

	while(std::cin >> item){
		BOOK.resize(i, item.isbn());
		i += 1;
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
