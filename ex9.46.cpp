#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;

void name_fixer(string &name, string prefix, string suffix){

	prefix.insert(prefix.size(), " ");
	name.insert(0, prefix);
	name.insert(name.size(), " ");
	name.insert(name.size(), suffix);

}

int main(){

	string name = "Dane Johnson";

	name_fixer(name, "Mr.", "III");

	cout << name << endl;

}
