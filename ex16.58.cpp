#include <iostream> 
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;

class StrVec{

public:

	// Default Constructor
	StrVec() = default;

	// Constructor	
	StrVec(initializer_list<string>);
	
	// Copy Constructor
	StrVec(StrVec& orig);

	// Copy Assignment Operator
	StrVec& operator=(StrVec& orig);

	// Destructor
	~StrVec();

	// Grow
	void add_element(string val);

	// Emplace
	template<class... Args> void emplace_back(Args&&... vals);

	// Shrink
	void remove_element();

	// Reserve
	string *reserve_space(int n){vec.allocate(n);}

	// Cancel
	string *cancel_space(string *spot, int n){vec.deallocate(spot, n);}

	// Print
	void print_elements();

	// Size
	int sz(){return this->num_elements;}

	// Get First
	string *get_first(){return this->start;}

	// Get Last
	string *get_last(){return this->last;}

private:
	allocator<string> vec;
	string *start;
	string *last;
	int num_elements = 0;
};

StrVec::StrVec(initializer_list<string> orig){

	for(auto i = orig.begin(); i != orig.end(); ++i){
		this->add_element(*i);
	}

}

StrVec::StrVec(StrVec& orig){
	this->vec = orig.vec;
	this->start = orig.start;
	this->last = orig.last;
	this->num_elements = orig.num_elements;
}

StrVec& StrVec::operator=(StrVec& orig){
	this->vec = orig.vec;
	this->start = orig.start;
	this->last = orig.last;
	this->num_elements = orig.num_elements;
}

StrVec::~StrVec(){

	if(this->num_elements > 0){
		for_each(this->start, this->last, [this](string s){this->remove_element();});
		this->cancel_space(this->start, this->num_elements);
		this->num_elements = 0;
		cout << "GoodBye" << endl;		
	}

}

void StrVec::add_element(string val){

	if(this->num_elements == 0){
		this->start = this->reserve_space(1);
		this->last = start;
		++this->last;
		this->vec.construct(this->start, val);
	} else {
		auto spot = this->reserve_space(this->num_elements + 1);
		auto end_spot = uninitialized_copy(this->start, this->last, spot);
		uninitialized_fill_n(end_spot, 1, val);
		this->start = spot;
		this->last = ++end_spot;
	}
	++this->num_elements;
}
	
template<class... Args> void StrVec::emplace_back(Args&&... vals){
	
	if(this->num_elements == 0){
		this->start = this->reserve_space(1);
		this->last = start;
		++this->last;
		this->vec.construct(this->start, forward<Args>(vals)...);
	} else {
		auto spot = this->reserve_space(this->num_elements + 1);
		auto end_spot = uninitialized_copy(this->start, this->last, spot);
		this->vec.construct(end_spot, forward<Args>(vals)...);
		this->start = spot;
		this->last = end_spot + 1;
	}
	this->num_elements += 1;
}

void StrVec::remove_element(){	

	if(this->num_elements == 0){
		cout << "No Elements Left To Remove" << endl;
	} else {
		this->vec.destroy(--this->last);
		--this->num_elements;
	}
}


void StrVec::print_elements(){

	for(auto k = this->start; k != this->last; ++k){
		cout << *k << endl;	
	}

}

int main(){

	StrVec Ex({"One", "Two", "Three"});
	Ex.emplace_back("Four");
	auto str_val = "Five";
	Ex.emplace_back(str_val);
	Ex.print_elements();

}
