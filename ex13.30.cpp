#include <iostream>
#include <string>

using namespace std;

static int HasPtr_Count = 0;

class HasPtr{

public:
	// Constructor
	HasPtr(const string &s = string()): ps(new string(s)), i(0) {++HasPtr_Count;}

	// Copy Constructor
	HasPtr(const HasPtr& orig): ps(orig.ps), i(orig.i) {++HasPtr_Count;}
	
	// Copy Assignment Operator
	HasPtr& operator=(HasPtr& orig){
		--HasPtr_Count;
		if(HasPtr_Count == 0){
			delete ps;
		}
		 ps = new string(*orig.ps);
		 i = orig.i;
	}

	// Destructor 
	~HasPtr(){
		if(--HasPtr_Count == 0){
			delete ps;
		}
	}

	// Swap Function
	void swap(HasPtr &rhs);

	// Set Values
	void set_string(string val){*(this->ps) = val;}
	void set_num(int val){this->i = val;}

	// Print Function
	void print_string(){cout << *(this->ps) << endl;}
	void print_string_address(){cout << this->ps << endl;}
	void print_num(){cout << this->i << endl;}
	
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

	HasPtr first("Sherlock Holmes");
	first.set_num(1);
	HasPtr second("John Watson");
	second.set_num(2);

	first.print_string_address();
	second.print_string_address();

	first.swap(second);

	first.print_string_address();
	second.print_string_address();

	first.print_string();
	first.print_num();
}
