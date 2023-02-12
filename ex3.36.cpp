#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl; using std::begin; using std::end;

int main()
{

	int arr_1[] = {5, 10, 15, 20, 25};
	int arr_2[] = {5, 10, 15, 20, 25};
	auto arr1_size = sizeof(arr_1) / sizeof(int);
	auto arr2_size = sizeof(arr_2) / sizeof(int);
	int check = 0;

	int *arr_p1 = arr_1, *arr_p2 = arr_2;

	while(arr_p1 != end(arr_1) && arr_p2 != end(arr_2)){
		if(arr1_size != arr2_size){
			cout << "These arrays aren't the same size!" << endl;
			break;
		}

		if(*(arr_p1) == *(arr_p2)){
			check += 1;
			cout << "Check" << endl;
		} else {
			cout << "These arrays are different!" << endl;
			break;
		}
		++arr_p1, ++arr_p2;
	}


	if(check == arr1_size){
		cout << "These arrays are the same!" << endl;
	}
}
