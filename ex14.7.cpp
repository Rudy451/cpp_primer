#include <iostream>
#include <memory>
#include <vector>

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

// Move Constructor
String(String&& orig) noexcept;

// Move-Assignment Constructor
String& operator=(String&& orig) noexcept;

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

// Print Num_Elements
const int get_count() const {return this->num_elements;}

// Grab First Element
char* get_start() const {return this->start;}

// Grab Second Element
char* get_last() const {return (this->last - 1);}

private:

allocator<char> vec;
char *start;
char *last;
int num_elements = 0;

};

// Move Constructor
String::String(String&& orig) noexcept: num_elements(orig.num_elements), start(orig.start), last(orig.last){

	orig.start = orig.last = nullptr;

}

// Move-Assignment Operator
String& String::operator=(String&& orig) noexcept{

	for(auto i = orig.start; i != orig.last; ++i){
		this->add(*i);
	};

	this->start = orig.start;
	this->last = orig.last;
	this->num_elements = orig.num_elements;
	orig.start = orig.last = nullptr;

}

// Copy Constructor
String::String(const String& orig): num_elements(orig.num_elements) {

	for(auto i = orig.start; i != orig.last; ++i){
		this->add(*i);
	};

}

// Copy-Assignment Operator
String& String::operator=(const String& orig){

	for(auto i = orig.start; i != orig.last; ++i){
		this->add(*i);
	};

	this->num_elements = orig.num_elements;

}

// Destructor
String::~String(){

	if(this->num_elements > 0){
		auto temp_spot = this->num_elements;
		for(auto i = this->last; i != this->start; --i){\
			this->remove();
		}
		this->cancel_space(this->start, temp_spot);
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

ostream &operator<<(ostream &os, const String &ex){

	os << "First: " << *(ex.get_start()) << " Last: " << *(ex.get_last()) << " Total: " << ex.get_count();
	return os;

}

int main(){

	vector<String> Stuff;
        String first_name("Dane");
        String middle_name("Christopher");
        String last_name("Johnson");
        String school_mascot("Gael");
        Stuff.push_back(first_name);
        Stuff.push_back(middle_name);
	cout << first_name << endl;
       // Stuff.push_back(last_name);
       // Stuff.push_back(school_mascot);
}
