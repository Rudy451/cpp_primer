#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	// version #1: conditional operators: less readable because everything has to be read sequentially on one line.
	int grade = 50;

	string finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : (grade >= 60 & grade <= 75) ? "low pass" : "pass";

	cout << finalgrade << endl;

	// version #2: if statements are more readible because you can quickly scan the conditions line by line.
	string finalgrade2;

	if(grade > 90){
		finalgrade2 = "high pass";
	} else if(grade < 60){
		finalgrade2 = "fail";
	} else if(grade >= 60 & grade <= 75){
		finalgrade2 = "low pass";
	} else {
		finalgrade2 = "fail";
	}
	
	cout << finalgrade2 << endl;
		
}


