#include <iostream>
#include <string>

using std::string; using std::cin; using std::cout; using std::istream; using std::ostream; using std::endl;

class Vehicle{
public:
	// Default Constuctor
	Vehicle(string first="Civic_Ex", unsigned second=2002, unsigned cnt=0, double price=55000): model(first), year(second), revenue(cnt * price) {}

	// Copy Assignment Operator
	Vehicle& operator=(const Vehicle& ex){
		model = ex.model; 
		year = ex.year;
		cnt = ex.cnt; 
		revenue = ex.revenue; 
		motor = ex.motor;
	}

	// Delete
	~Vehicle(){cout << "Goodbye" << endl;}
	
	Vehicle& operator+=(const Vehicle& rhs){
	
		cnt += rhs.cnt;
		revenue += rhs.revenue;
		return *this;

	}

	// Operations
	string car_model() const {return model;}
	unsigned car_year() const {return year;}
	double car_rev() const {return revenue;}
	string motor_type(string motor) const {return motor;}

private:
	// Members
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

	Vehicle Buick = Buick_One;
	Buick += Buick_Two;
	cout << Buick.car_rev() << endl;

	return 0;
}

