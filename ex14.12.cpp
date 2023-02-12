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
	
	friend istream &operator>>(istream &is, Vehicle &ex);
	
private:
	string model;
	unsigned year;
	unsigned cnt;
	double revenue;
	string motor;
};

istream &operator>>(istream &is, Vehicle &ex){

	double price;
	is >> ex.model >> ex.year >> ex.cnt >> price;
	if(is){
		ex.revenue = price * ex.cnt;	
	} else {
		ex = Vehicle();
	}

	return is;

}

ostream &operator<<(ostream &os, const Vehicle &ex){

	os << "Model: " << ex.car_model() << ", Year: " << ex.car_year() << ", Revenue: " << ex.car_rev();
	return os;

}

int main(){

	Vehicle Tesla;
	cin >> Tesla;
	cout << Tesla << endl;
	return 0;
}

