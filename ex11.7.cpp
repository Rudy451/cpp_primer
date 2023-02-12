#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; using std::endl; using std::map; using std::string; using std::vector;

int main(){

	map<string, vector<string>> family = {
	{"Jackson", vector<string> {"Jackie", "Tito", "Jermaine", "Marlon", "Michael"}},
	{"Manning", vector<string> {"Peyton", "Eli"}}};

	family["St. Brown"] = vector<string> {"Equanimeous","Amon-Ra Julian Heru"};
	family["Manning"].push_back("Cooper");

	cout << family["Manning"][0] << " " << family["Manning"][1] << " " << family["Manning"][2] << endl;
	cout << family["St. Brown"][0] << " " << family["St. Brown"][1] << endl;
	
}
