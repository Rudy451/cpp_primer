#include <iostream>
#include <string>
#include "Sales_data.h"

int total_sold = 0;
Sales_data item_1, item_2;
std::string Answer;

int main()
{

	std::cout << "Enter Book ID: " << std::endl;
	std::cin >> item_1.book_id;
	std::cout << "Enter Units Sold: " << std::endl;
	std::cin >> item_1.units_sold;
	total_sold += item_1.units_sold;

	std::cout << "Continue? " << std::endl;

	while(std::cin >> Answer){
		std::cout << "Enter Book ID: " << std::endl;		
		std::cin >> item_2.book_id;
		std::cout << "Enter Units Sold: " << std::endl;
		std::cin >> item_2.units_sold;
		if(item_1.book_id == item_2.book_id){
			total_sold += item_2.units_sold;
			std::cout << "Continue? " << std::endl;
		} else {
			std::cout << "New Book ID, Continue? " << std::endl;
		}

		item_2 = item_1;
		
	}
	
	std::cout << total_sold << std::endl;
	
	return 0;
}
