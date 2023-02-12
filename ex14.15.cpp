#include <iostream>
#include <string>

using std::string; using std::cin; using std::cout; using std::istream; using std::ostream; using std::endl;

class Vehicle{
public:
	Vehicle(string first="Civic_Ex", unsigned second=2002, unsigned cnt=1, double price=55000): model(first), year(second), revenue(cnt * price) {}
	Vehicle(string uno, unsigned dos): Vehicle(uno, dos, 1, 55000) {}
	Vehicle(string motor): Vehicle()  {motor_type(motor);}

	string car_model() const {return this->model;}
	unsigned car_year() const {return this->year;}
	string motor_type(string motor) const {return this->motor;}
	double car_rev() const {return this->revenue;}	

private:
	string model;
	unsigned year;
	unsigned cnt;
	double revenue;
	string motor;
};

ostream &operator<<(ostream &os, const Vehicle &ex){

	os << "Model: " << ex.car_model() << ", Year: " << ex.car_year() << ", Revenue: " << ex.car_rev();
	return os;

}

double operator+(const Vehicle &lhs, const Vehicle &rhs){

	double temp = lhs.car_rev();
	temp += rhs.car_rev();
	return temp;

}

double operator+=(const Vehicle &lhs, const Vehicle &rhs){

	double temp = lhs.car_rev() + rhs.car_rev();
	return temp;
}

int main(){

	Vehicle Honda;
	Vehicle Buick("Riviera", 1980, 2, 40000);
	cout << Honda + Buick << endl;
	return 0;
}

