#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int box[10];
int box_2[10];

vector<int> box_3(10);

int main()
{
	for(size_t i = 0; i < (sizeof(box) / sizeof(int)); ++i){
		box[i] = i;	
	}
	
	int (&box_2)[10] = box;

	for(size_t i = 0; i < (sizeof(box_2) / sizeof(int)); ++i){
		cout << (box_2)[i] << " ";
	}

	cout << endl;

	for(auto i = 0; i < box_3.size(); ++i){
		box_3[i] = i;
		cout << box_3[i] << " ";
	}

	cout << endl;

	vector<int> box_4 = box_3;

	for(auto i = 0; i < box_4.size(); ++i){
                cout << box_4[i] << " ";
        }


	cout << endl;

}
