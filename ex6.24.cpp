#include <iostream>

using std::begin; using std::end; using std::cout; using std::endl;

void print(const int *beg, const int *end)
{	
	while(beg != end){
		cout << *beg++ << endl;
	}

}

int main()
{
	int j[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print(begin(j), end(j));
	
	return 0;

}
