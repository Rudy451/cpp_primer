#include <iostream>
#include <string>

using std::string; using std::cin; using std::cout; using std::istream; using std::ostream; using std::endl;

class Vehicle{
public:
	Vehicle(string first="Civic_Ex", unsigned second=2002, unsigned cnt=1, double price=55000): model(first), year(second), revenue(cnt * price) {}
	Vehicle(string uno, unsigned dos): Vehicle(uno, dos, 1, 55000) {}
	Vehicle(string motor): Vehicle()  {motor_type(motor);}

	string car_model(){return model;}
	unsigned car_year(){return year;}
	string motor_type(string motor){return motor;}

private:
	string model;
	unsigned year;
	unsigned cnt;
	double revenue;
	string motor;
};

int main(){

	Vehicle Honda;
	Vehicle Buick("Riviera", 1980, 40000);

	cout << Honda.car_model() << endl;
	cout << Buick.car_model() << endl;

	return 0;
}

