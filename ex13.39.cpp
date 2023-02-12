#include <iostream>
#include <memory>

using namespace std;

// Write your own version of StrVec, with reserve, capacity, and resize
// Page 602

class StrVec{

public:
	// Default Constructor
	StrVec(){this->spot = vec.allocate(10);}

	// Copy Constructor
	StrVec(StrVec&){}

	// Copy Assignment Operator
	StrVec& operator=(StrVec& orig){}

	// Destructor
	~StrVec(){}

	// Grow
	void add_element(string val);

	// Shrink
	void remove_element(string target);

	// Reserve
	string *reserve_space(int n){vec.allocate(n);}

	// Size
	int sz(){return this->num_elements;}

	// Capacity
	int cap();	

private:
	allocator<string> vec;
	int num_elements = 0;
	string *spot;
};

void StrVec::add_element(string val){

	this->spot = this->reserve_space(this->num_elements + 1);
	vec.construct(spot, val);
	++this->num_elements;

}

void StrVec::remove_element(string target){

	auto temp_spot = this->spot;

	while(*(temp_spot) != target){
		cout << "YAY" << endl;
		--temp_spot;
	}	
	vec.destroy(temp_spot);
	vec.deallocate(temp_spot, 1);
	--this->num_elements;

}

int main(){

	StrVec Ex;
	Ex.add_element("Start");
	cout << Ex.sz() << endl;
	Ex.add_element("End");
	cout << Ex.sz() << endl;
	Ex.remove_element("Start");
	cout << Ex.sz() << endl;
	
}
