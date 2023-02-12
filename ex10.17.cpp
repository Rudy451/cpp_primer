#include <iostream>
#include <vector>
#include <algorithm>
#include "Sales_item.h"

using std::cout; using std::endl; using std::vector; using std::sort;

int main(){

	Sales_item first("Harry Potter and the Sorceror's Stone");
	Sales_item second("Harry Potter and the Chamber of Secrets");
	Sales_item third("Harry Potter and the Prisoner of Azkaban");
 	vector<Sales_item> book_list = {first, second, third};

	stable_sort(book_list.begin(), book_list.end(), [](const Sales_item &first, const Sales_item &second){return first.isbn() < second.isbn();});

	for(size_t i = 0; i < book_list.size(); ++i){
		cout << book_list[i].isbn() << " ";
	}

	cout << endl;
}
