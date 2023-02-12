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
	
	// Move Constructor
	StrVec(StrVec&& orig) noexcept;

	// Move Assignment Operator
	StrVec& operator=(StrVec&& orig) noexcept;	

	// Copy Constructor
	StrVec(const StrVec& orig);

	// Copy Assignment Operator
	StrVec& operator=(const StrVec& orig);

	// Destructor
	~StrVec();

	// Grow
	void add_element(string val);

	// Shrink
	void remove_element();

	// Reserve
	string *reserve_space(int n){vec.allocate(n);}

	// Cancel
	string *cancel_space(string *spot, int n){vec.deallocate(spot, n);}

	// Print
	void print_elements();

	// Size
	int sz() const {return this->num_elements;}

	// Compare
	bool Vec_Comp(const StrVec &Other) const;

	// Get First
	string *get_first() const {return this->start;}

	// Get Last
	string *get_last() const {return this->last;}

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

StrVec::StrVec(StrVec&& orig) noexcept: vec(orig.vec), start(orig.start), last(orig.last), num_elements(orig.num_elements){
	orig.start = orig.last = nullptr;
}

StrVec& StrVec::operator=(StrVec&& orig) noexcept{
	this->vec = orig.vec;
	this->start = orig.start;
	this->last = orig.last;
	this->num_elements = orig.num_elements;
	orig.start = orig.last = nullptr;
}

StrVec::StrVec(const StrVec& orig): vec(orig.vec), start(orig.start), last(orig.last), num_elements(orig.num_elements){}

StrVec& StrVec::operator=(const StrVec& orig){
	this->vec = orig.vec;
	this->start = orig.start;
	this->last = orig.last;
	this->num_elements = orig.num_elements;
}

StrVec::~StrVec(){

	if(this->num_elements > 0){
		auto temp_spot = this->num_elements;
		for(auto i = this->last; i != this->start; --i){
			this->remove_element();
		}
		this->cancel_space(this->start, temp_spot);
//		cout << "GoodBye" << endl;
		
	}

}

void StrVec::add_element(string val){

	if(this->num_elements == 0){
		this->start = this->reserve_space(1);
		this->last = start;
		++this->last;
		this->vec.construct(this->start, val);
	} else {
		auto spot = this->reserve_space(num_elements + 1);
		auto end_spot = uninitialized_copy(this->start, this->last, spot);
		uninitialized_fill_n(end_spot, 1, val);
		this->start = spot;
		this->last = ++end_spot;
	}
	++this->num_elements;
}

void StrVec::remove_element(){	

	if(this->num_elements == 0){
		cout << "No Elements Left To Remove" << endl;
	} else {
		this->vec.destroy(--this->last);
	}
	--this->num_elements;
}


void StrVec::print_elements(){

	for(auto k = this->start; k != this->last; ++k){
		cout << *k << endl;	
	}

}

bool StrVec::Vec_Comp(const StrVec &Other) const{

	auto lhs_temp = this->get_first();
	auto rhs_temp = Other.get_first();
	for(int i = 0; i < this->sz(); ++i){
		if(*(lhs_temp) != *(rhs_temp)){return 0;}
		++lhs_temp;
		++rhs_temp;
	}

	return 1;

}

bool operator==(const StrVec &lhs, const StrVec &rhs){

	return (lhs.sz() == rhs.sz()) && lhs.Vec_Comp(rhs);

}

bool operator!=(const StrVec &lhs, const StrVec &rhs){

	return !(lhs == rhs);	

}

int main(){

	StrVec first({"Lets", "Play", "A", "Game"});
	StrVec second({"Lets", "Play", "a", "Game"});
	cout << (first == second) << endl;

}
