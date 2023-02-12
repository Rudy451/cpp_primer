#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	// Create matrix Ia
	int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	using int_array = int[4];
	using row_index = size_t;
	using col_index = size_t;

	// Version #1: Range For iteration
	for(int_array &row: ia){
		for(const int col : row){
			cout << col << endl;
		}
	}


	// Version #2: Subscripts Iteration
	for(row_index i = 0; i != 3; ++i){
		for(col_index j = 0; j != 4; ++j){
			cout << ia[i][j] << endl;
		}
	}

	// Version #3: Pointers Iteration
	for(int_array *i = ia; i != ia + 3; ++i){
		for(int *j = *i; j != *i + 4; ++j){
			cout << *j << endl;
		}
	}
}


