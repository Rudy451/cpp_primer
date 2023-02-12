#include <iostream>
#include "Sales_data.h"

using std::cin; using std::cout; using std::endl; using std::cerr;

int main()
{
        Sales_data total_sales; // variable to hold the running sum
        // read and process the remaining transactions
        if(cin >> total_sales.book_id){
		cin >> total_sales.total;
                Sales_data trans; // variable to hold the running sum
                // read and process the remaining transactions
                while(cin >> trans.book_id){
			cin >> trans.total;
                        // if we're still processing the same book.
                        if(total_sales.book_id == trans.book_id){
                                total_sales.total += trans.total; // update the running total
                        } else {
                                // print results for the previous book
                                cout << total_sales.book_id << ": " << total_sales.total << endl;
                                total_sales = trans; // total now refers to the next book
                        }
                }
                cout << total_sales.book_id << ": " << total_sales.total << endl; // print the last transaction
        } else {
                // no input! warn the user.
                cerr << "No data?!" << endl;
                return -1; // indicate failure
        }

        return 0;
}
