#include <iostream>

int main()
{
	int first = 0, second = 0;

	std::cout << "Enter some numbers :" << std::endl;
	std::cin >> first;

	while(std::cin >> second){
		if(first < second){
			std::cout << "Smaller number is: " << first << std::endl;
		} else {
			first = second;
		}
	}
	return 0;
}
			


