#include <iostream>
#include <string>

using namespace std;

static int master_id = 0;

class Employee{

public:
	// Default Constructor
	Employee(): id(++master_id) {};

	// Constructor with Name;
	Employee(string person): name(person), id(++master_id) {} 

	// Add Name
	void Insert_Name(string person){this->name = person;}

	// New Id
	void Insert_ID(int new_id){this->id = id;}

	// Return Stuff
	void Grab(){cout << this->name << ": " << this->id << endl;}

private:
	string name;
	int id;

};

int main(){

	Employee First;
	First.Insert_Name("Powell");
	First.Grab();

	Employee Second("Donovan");
	Second.Grab();
}
