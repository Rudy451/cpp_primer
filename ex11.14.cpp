#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::map; using std::pair; using std::string; using std::vector;

int main(){

	string bday;

	map<string, vector<string>> family = {
	{"Jackson", vector<string> {"Jackie", "Tito", "Jermaine", "Marlon", "Michael"}},
	{"Manning", vector<string> {"Peyton", "Eli"}}};

	family["St. Brown"] = vector<string> {"Equanimeous","Amon-Ra Julian Heru"};
	family["Manning"].push_back("Cooper");

	vector<pair<string, string>> birth_date;

	for(int i = 0; i < 5; ++i){
		cin >> bday;
		birth_date.emplace_back(make_pair(family["Jackson"][i], bday));
		cout << birth_date[i].first << " " << birth_date[i].second << endl; 
	}
}
