#include <iostream> 
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T> class Vec{

public:

	// Default Constructor
	Vec() = default;

	// Constructor	
	Vec(initializer_list<T>);
	
	// Copy Constructor
	Vec(Vec<T>& orig);

	// Copy Assignment Operator
	Vec<T>& operator=(Vec<T>& orig);

	// Destructor
	~Vec();

	// Grow
	void add_element(T val);

	// Shrink
	void remove_element();

	// Reserve
	T *reserve_space(int n){vec.allocate(n);}

	// Cancel
	T *cancel_space(T *spot, int n){vec.deallocate(spot, n);}

	// Print
	void print_elements();

	// Size
	int sz(){return this->num_elements;}

	// Get First
	T *get_first(){return this->start;}

	// Get Last
	T *get_last(){return this->last;}

private:
	allocator<T> vec;
	T *start;
	T *last;
	int num_elements = 0;
};

template<typename T> Vec<T>::Vec(initializer_list<T> orig){

	for(auto i = orig.begin(); i != orig.end(); ++i){
		this->add_element(*i);
	}
	
}

template<typename T> Vec<T>::Vec(Vec<T>& orig){
	this->vec = orig.vec;
	this->start = orig.start;
	this->last = orig.last;
	this->num_elements = orig.num_elements;
	
}

template<typename T> Vec<T>& Vec<T>::operator=(Vec<T>& orig){
	this->vec = orig.vec;
	this->start = orig.start;
	this->last = orig.last;
	this->num_elements = orig.num_elements;
}

template<typename T> Vec<T>::~Vec(){

	if(this->num_elements > 0){
		for_each(this->start, this->last, [this](T s){this->remove_element();});
		this->cancel_space(this->start, this->num_elements);
		this->num_elements = 0;
		cout << "GoodBye" << endl;		
	}

}

template<typename T> void Vec<T>::add_element(T val){

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

template<typename T> void Vec<T>::remove_element(){	

	if(this->num_elements == 0){
		cout << "No Elements Left To Remove" << endl;
	} else {
		this->vec.destroy(--this->last);
		--this->num_elements;
	}
}


template<typename T> void Vec<T>::print_elements(){

	for(auto k = this->start; k != this->last; ++k){
		cout << *k << endl;	
	}

}

int main(){

	Vec<string> Ex({"One", "Two", "Three"});
	Ex.print_elements();
	Vec<int> Ex1({1, 2, 3});
	Ex1.print_elements();
}
