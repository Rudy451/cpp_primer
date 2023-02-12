#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

using std::cin; using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	vector<string> scores = {"F", "D", "C", "B", "A"};
	
	int grade = 68;

	cout << ((grade < 60) ? scores[4] : scores[(grade - 50) / 10]);
	cout << ((grade % 10 > 7) ? '+' : ' ');
	cout << ((grade % 10 < 3) ? '-' : ' ');
	cout << endl;

}


