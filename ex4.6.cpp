#include <iostream>

using std::cin; using std::cout; using std::endl; 

int main()
{

	int value;
	while(cin >> value){
		if(value % 2 == 0){
				cout << "Even Number" << endl;
		}
	}

	return 0;
	
}
