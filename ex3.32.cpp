#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int box[10];

int main()
{
	for(size_t i = 0; i < (sizeof(box) / sizeof(int)); ++i){
		box[i] = i;
		cout << box[i] << ", ";		
	}
	
	cout << endl;
}
