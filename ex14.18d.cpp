#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class String{

public:

// Default Constructor
String() = default; 

// Alternative Constructor
String(const char *word){
			for(auto i = 0; word[i] != '\0'; ++i){
				this->add(word[i]);
			};
		} 

// Copy Constructor
String(const String& orig);

// Copy-Assignment Operator
String& operator=(const String& orig);

// Destructor
~String();

// Reallocate Space
char *reserve_space(int ct){this->vec.allocate(ct);}

// Cancel Space
char *cancel_space(char *spot, int n){vec.deallocate(spot, n);}

// Add Character
void add(char letter);

// Remove Character
void remove();

// Print Character
void print_stuff();

// Return Num Chars
int get_sz() const {return this->num_elements;}

// Compare
bool Str_Comp(const String &Other) const;

// Grab First Element
char* get_start() const {return this->start;}

// Grab Second Element
char* get_last() const {return this->last;}

private:

allocator<char> vec;
char *start;
char *last;
int num_elements = 0;

};

String::String(const String& orig){

	cout << "Copy Constructor in Use" << endl;

	for(auto i = orig.start; i != orig.last; ++i){
		this->add(*i);
	};

	this->num_elements = orig.num_elements;
}

String& String::operator=(const String& orig){

	cout << "Copy Assignment Operator in Use" << endl;

	for(auto i = orig.start; i != orig.last; ++i){
		this->add(*i);
	};

	this->num_elements = orig.num_elements;

}

// Destructor
String::~String(){

	if(this->num_elements > 0){
		for(auto i = this->last; i != this->start; --i){\
			this->remove();
		}
		this->cancel_space(this->start, this->num_elements);
		this->num_elements = 0;
		//cout << "GoodBye" << endl;
	}

}

void String::add(char val){

	if(this->num_elements == 0){
		this->start = this->reserve_space(1);
		this->last = this->start;
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

void String::remove(){

	if(this->num_elements == 0){	
		cout << "No Elements Left To Remove" << endl;
	} else {
		this->vec.destroy(--this->last);
		--this->num_elements;
	}
}


void String::print_stuff(){

	for(auto i = this->start; i != this->last; ++i){
		cout << *i;
	}
	cout << endl;

}

bool String::Str_Comp(const String &Other) const{

	auto lhs_temp = this->get_start();
	auto rhs_temp = Other.get_start();
	for(auto i = 0; i != this->get_sz(); ++i){
		if(*(lhs_temp) != *(rhs_temp)){return 0;}
		++lhs_temp;
		++rhs_temp;
	}

	return 1;

}

bool operator==(const String &lhs, const String &rhs){

	return (lhs.get_sz() == rhs.get_sz()) && (lhs.Str_Comp(rhs));

}

bool operator!=(const String &lhs, const String &rhs){

	return !(lhs == rhs);

}

bool operator>(const String &lhs, const String &rhs){

	return lhs.get_sz() > rhs.get_sz();

}

bool operator<(const String &lhs, const String &rhs){

	return lhs.get_sz() < rhs.get_sz();

}

int main(){

	String first("Dane");
	String last("Dan");
	cout << (first < last) << endl;

}
