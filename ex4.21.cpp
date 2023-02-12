#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{

	vector<int> int_list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for(auto vect_int = int_list.begin(); vect_int != int_list.end(); ++vect_int){
		((*(vect_int) % 2 != 0) ? *(vect_int) *= 2 : *(vect_int));
		cout << *(vect_int) << endl;
	}
	

}


