#include <iostream>
#include <map>
#include <string>

using std::cin; using std::cout; using std::endl; using std::map; using std::string;


int main(){

	map<string, int> QB_Num = {{"Brady", 0}, {"Manning", 0}, {"Rodgers", 0}, {"Brees", 0}};

	for(map<string, int>::iterator iter = QB_Num.begin(); iter != QB_Num.end(); ++iter){
		cin >> iter->second;
		cout << iter->first << " " << iter->second << endl;
	}

}
