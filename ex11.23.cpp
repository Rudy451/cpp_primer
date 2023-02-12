#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::multimap; using std::pair; using std::string; using std::vector;

int main(){

	multimap<string, string> family;
	family.insert({"Jackson", "Jackie"});
	family.insert({"Jackson", "Tito"});
	family.insert({"Jackson", "Jermaine"});
	family.insert({"Jackson", "Marlon"});
	family.insert({"Jackson", "Michael"});

	for(multimap<string, string>::iterator i = family.begin(); i != family.end(); ++i){
		cout << i->first << " " << i->second << endl;
	}
}
