#include <iostream>
#include <string>

using std::string; using std::cin; using std::cout; using std::istream; using std::ostream; using std::endl;

class Vehicle{
public:
	Vehicle(string first="Civic_Ex", unsigned second=2002, unsigned cnt=1, double price=55000): model(first), year(second), revenue(cnt * price) {}
	Vehicle(string uno, unsigned dos): Vehicle(uno, dos, 1, 55000) {}
	Vehicle(string motor): Vehicle()  {motor_type(motor);}

	string car_model() const {return model;}
	unsigned car_year() const {return year;}
	string motor_type(string motor) const {return motor;}

private:
	string model;
	unsigned year;
	unsigned cnt;
	double revenue;
	string motor;
};

bool operator==(const Vehicle &lhs, const Vehicle &rhs){

	return ((lhs.car_model() == rhs.car_model()) && (lhs.car_year() == rhs.car_year()));

}

bool operator!=(const Vehicle &lhs, const Vehicle &rhs){

	return !(lhs == rhs);

}


int main(){

	Vehicle Buick_One("Riviera", 1980, 40000);
	Vehicle Buick_Two("Riviera", 1979, 37500);

	cout << (Buick_One != Buick_Two) << endl;

	return 0;
}

