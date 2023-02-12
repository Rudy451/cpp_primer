#include <iostream>
#include <string>

using namespace std;

class Shape{

public: 
	Shape() = default;
	Shape(int val): num_sides(val) {}
	Shape(string val): color(val) {}
	Shape(int val_one, string val_two): num_sides(val_one), color(val_two) {}
	virtual void construct(int val_one, string val_two){this->num_sides = val_one; this->color = val_two;}
protected:
	int num_sides;
	string color;

};

class Two_Dim_Shape: public Shape{
public:
	Two_Dim_Shape() = default;
	Two_Dim_Shape(int val_one, string val_two): Shape(val_one, val_two) {}
	Two_Dim_Shape(int val_one, int val_two, string val_three): radius(val_one), Shape(val_two, val_three) {}
	Two_Dim_Shape(int val_one, int val_two, int val_three, string val_four): length(val_one), height(val_two), Shape(val_three, val_four) {}
	void construct(int val_one, string val_two, int val_three){this->num_sides = val_one; this->color = val_two; this->radius = val_three;}
	void construct(int val_one, string val_two, int val_three, int val_four){this->num_sides = val_one; this->color = val_two; this->length = val_three; this->height = val_four;}
protected:
	int radius;
	int length;
	int height;
};

class Three_Dim_Shape: public Two_Dim_Shape{
public:
	Three_Dim_Shape() = default;
	Three_Dim_Shape(int val_one, int val_two, string val_three): num_dim(val_one), Two_Dim_Shape(val_two, val_three) {}
	void construct(int val_one, string val_two, int val_three, int val_four){this->num_sides = val_one; this->color = val_two; this->radius = val_three; this->num_dim = val_four;}
	void construct(int val_one, string val_two, int val_three, int val_four, int val_five){this->num_sides = val_one; this->color = val_two; this->length = val_three; this->height = val_four; this->num_dim = val_five;}
	
protected:
	int num_dim;
};


int main(){

	Two_Dim_Shape Circle(4, 1, "Red");
	Two_Dim_Shape Square(3, 3, 4, "Blue");
	Three_Dim_Shape Sphere(3, 1, "Red");
	Three_Dim_Shape Box(3, 4, "Blue");
		

}
