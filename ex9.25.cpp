#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main(){

	vector<int> temp = {1, 2, 3};
	temp.erase(temp.begin(), temp.begin()+1);
	cout << temp.front() << endl;	
	temp.erase(temp.begin()+3, temp.begin()+4);
	cout << temp.size() << endl;

}
