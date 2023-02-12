#include <iostream>

struct Player{
double height;
double weight;
double forty;
std::string college;
};

int main()
{
	Player Aaron_Rodgers;
	Aaron_Rodgers.height = 1.88;
	Aaron_Rodgers.weight = 225;
	Aaron_Rodgers.forty = 4.71;
	Aaron_Rodgers.college = "California";

	std::cout << Aaron_Rodgers.height << std::endl;
	std::cout << Aaron_Rodgers.weight << std::endl;
	std::cout << Aaron_Rodgers.forty << std::endl;
	std::cout << Aaron_Rodgers.college << std::endl;

	return 0;
}
