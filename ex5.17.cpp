#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::vector; using std::min; using std::endl;

vector<int> vect_1 = {0, 1, 1, 3};
vector<int> vect_2 = {0, 1, 1, 3, 4};


int main()
{
	for(int i = 0; i < min(vect_1.size(), vect_2.size()); ++i){
		if(vect_1[i] != vect_2[i]){
			cout << "FALSE" << endl;
			break;
		} else if(vect_2[min(vect_1.size(), vect_2.size())] != 0){
			cout << "TRUE" << endl;
			break;
		}
	}

	return 0;
}



