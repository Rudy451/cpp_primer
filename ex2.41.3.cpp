#include <iostream>
#include "Sales_data.h"

int main()
{
        Sales_data total_sales; // variable to hold the running sum
        // read and process the remaining transactions
        if(std::cin >> total_sales.book_id){
		std::cin >> total_sales.total;
                Sales_data trans; // variable to hold the running sum
                // read and process the remaining transactions
                while(std::cin >> trans.book_id){
			std::cin >> trans.total;
                        // if we're still processing the same book.
                        if(total_sales.book_id == trans.book_id){
                                total_sales.total += trans.total; // update the running total
                        } else {
                                // print results for the previous book
                                std::cout << total_sales.book_id << ": " << total_sales.total << std::endl;
                                total_sales = trans; // total now refers to the next book
                        }
                }
                std::cout << total_sales.book_id << ": " << total_sales.total << std::endl; // print the last transaction
        } else {
                // no input! warn the user.
                std::cerr << "No data?!" << std::endl;
                return -1; // indicate failure
        }

        return 0;
}
