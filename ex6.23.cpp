#include <iostream>

using std::cin; using std::cout; using std::find; using std::begin; using std::end; using std::endl;

// Using an explicit marker
void print_1(const int *num, int count){
	for(count; count != 0; --count){
		cout << *num++ << endl;
	}
}

// Using standard library conventions
void print_2(const int *beg, const int *end){
	while(beg != end){
		cout << *beg++ << endl;
	}
}

// Explicitly passing a size parameter
void print_3(const int *num, size_t size){
	for(size_t i = 0; i != size; ++i){
		cout << *(num)++ << endl;
	}
}

int main()
{
	int i = 0, j[2] = {0, 1};
	// Prints i
	print_1(&i, 1);
	print_1(j, 2);
	print_2(&i, &i+1);
	print_2(begin(j), end(j));
	print_3(&i, (sizeof(i) / sizeof(int)));
	print_3(j, (sizeof(j) / sizeof(int)));
	
	return 0;

}
