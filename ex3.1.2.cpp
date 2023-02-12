#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin; using std::cout; using std::endl;

int total_sold = 0;
Sales_data item_1, item_2;
std::string Answer;

int main()
{

        cout << "Enter Book ID: " << endl;
        cin >> item_1.book_id;
        cout << "Enter Units Sold: " << endl;
        cin >> item_1.units_sold;
        total_sold += item_1.units_sold;

        cout << "Continue? " << endl;

        while(std::cin >> Answer){
                cout << "Enter Book ID: " << endl;
                cin >> item_2.book_id;
                cout << "Enter Units Sold: " << endl;
                cin >> item_2.units_sold;
                if(item_1.book_id == item_2.book_id){
                        total_sold += item_2.units_sold;
                        cout << "Continue? " << endl;
                } else {
                        cout << "New Book ID, Continue? " << endl;
                }

                item_2 = item_1;

        }

        cout << total_sold << endl;

        return 0;
}                                
