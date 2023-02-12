#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static int HasPtr_Count = 0;

class HasPtr{

public:
	// Constructor
	HasPtr(const string &s = string()): ps(new string(s)), i(0) {++HasPtr_Count;}

	// Move Constructor
	HasPtr(HasPtr&& orig) noexcept: ps(orig.ps), i(orig.i) {
		++HasPtr_Count;
		orig.ps = nullptr;
	}

	// Move-Assignment Operator
	HasPtr& operator=(HasPtr&& orig) noexcept{
		if(this != &orig){
			--HasPtr_Count;
			ps = orig.ps;
			i = orig.i;
			orig.ps = nullptr;
		}
		cout << "Moved" << endl;
		return *this;
	}

	// Copy And Swap	
	HasPtr& operator=(HasPtr rhs){
		swap(rhs);
		cout << "Copied/Moved" << endl;
		return *this;
	}

	// Less Than Operator
	bool operator<(const HasPtr& orig){
		return this->i < orig.i;
	}

	// Destructor 
	~HasPtr(){
		if(--HasPtr_Count == 0){
			delete ps;
		}
		cout << "BYE" << endl;
	}

	// Swap Function
	void swap(HasPtr &rhs);

	// Set Values
	void set_string(string val){*(this->ps) = val;}
	void set_num(int val){this->i = val;}

	// Print Function
	string print_string(){return *(this->ps);}
	void print_string_address(){cout << this->ps << endl;}
	int print_num(){return this->i;}

private:	
	// Data Members
	string *ps;
	int i;

};

void HasPtr::swap(HasPtr &rhs){

	using std::swap;
	swap(this->ps, rhs.ps);
	swap(this->i, rhs.i);
	cout << "This Function Has Been Used." << endl;

}
	
int main(){


	HasPtr first("John Watson");
	first.set_num(5);
	HasPtr second("Jim Moriarty");
	second.set_num(4);
	HasPtr third;
	third = second;

}
