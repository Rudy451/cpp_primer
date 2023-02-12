#include <iostream>
#include <string>

using std::cin; using std::cout; using std::string; using std::initializer_list; using std::endl;

int error_msg(initializer_list<string> il){

	for(const auto &elem : il)
		cout << elem << " ";
	cout << endl;
}

int main()
{
	error_msg({"Functionx", "right", "wrong"});
	
	return 0;
}
