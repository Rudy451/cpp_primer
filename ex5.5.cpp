#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	vector<string> scores = {"F", "D", "C", "B", "A"};
	
	int grade = 71;

	if(grade < 60){
		cout << scores[0];
	} else {
		cout << scores[(grade - 50)/10];
		if(((grade - 50) % 10) < 3){
			cout << "-" << endl;
		}else if(((grade - 50) % 10) > 7){
			cout << "+" << endl;
		}else{
			cout << endl;
		} 
	}

}


