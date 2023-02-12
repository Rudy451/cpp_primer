#include <iostream>
#include <stdexcept>
	
using std::cin; using std::cout; using std::endl; using std::runtime_error;

int main()
{

	float num, num2;

	Retry:
		try{
			cout << "Please enter two numbers: " << endl;
			cin >> num >> num2;	
			if(num2 == 0){throw runtime_error("Can't divide by zero. ");}
			cout << "Answer is: " << (num / num2) << endl;
		} catch(runtime_error err){
			cout << err.what() << endl;
			goto Retry;
		}	
}
