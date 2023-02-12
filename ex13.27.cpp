#include <iostream>
#include <string>

using namespace std;

static int HasPtr_Count = 0;

struct HasPtr{

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

	// Data Members
	string *ps;
	int i;

};

int main(){

	HasPtr first("Sherlock Holmes");

}
