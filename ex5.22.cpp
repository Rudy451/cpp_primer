#include <iostream>
	
using std::size_t;


int main()
{
	int sz;
	while(sz <= 0){
		sz = sizeof(sz);
		++sz;
	}	

	return 0;
}
