#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout; using std::endl; using std::map; using std::string; using std::vector;

int main(){

	map<string, vector<int>> show_times = {{"The Office", {3, 5, 7}},
					       {"South Park", {8, 9, 11}}};

	map<string, vector<int>>::iterator spot = show_times.find("The Office");
}
