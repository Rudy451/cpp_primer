#include <iostream>

using std::cin; using std::cout; using std::endl;

int fact(int val){
	if(val == 1){
		return val;
	}
	else{
		val *= fact(val - 1);
	}
}

int main()
{
	int val;

	cout << "Please enter a number & we'll find its factorial: " << endl;
	cin >> val;
	cout << "The factorial of: " << val << " is: " << fact(val) << ". " << endl;
	return 0;	

}


