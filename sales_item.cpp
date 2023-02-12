#include <iostream>
#include "Sales_item.h"
#include "Sales_Data.h"

int main()
{
	Sales_item Book1, Book2, Total;

	std::cin >> Book1;
	std::cout << Book1 << std::endl;
	Total = Book1;
	// read ISBN, number of copies sold, and sales price
	while(std::cin >> Book2){
		if(Book1.isbn() == Book2.isbn()){
			std::cout << "\n" << Book2 << std::endl;
			Total += Book2;
			Book1 = Book2;
		}
	}
	std::cout << Total << std::endl;
	// write ISBN, number of copies sold, total revenue, and average price

//	Sales_item item1, item2;
//	std::cin >> item1 >> item2;
//	if(item1.isbn() == item2.isbn()){
//		std::cout << item1 << "\n" << item2 << std::endl;
//	}
//	std::cout << item1 + item2 << std::endl;
	return 0;
}


