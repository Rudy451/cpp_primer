#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;

void name_fixer(string &name, string prefix, string suffix){

	prefix.append(" ");
	name.insert(name.begin(), prefix.begin(), prefix.end());
	name.append(" ");
	name.append(suffix);

}

int main(){

	string name = "Dane Johnson";

	name_fixer(name, "Mr.", "III");

	cout << name << endl;

}
