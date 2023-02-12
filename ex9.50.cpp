#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl; using std::string; using std::vector;

vector<string> s = {"1.0", "2.2", "3.4", "4.5", "5.6"};

float string_num_sum = 0;

int main(){


	for(size_t i = 0; i < s.size(); ++i){	
		string_num_sum += stof(s[i]);
	}

	cout << string_num_sum << endl;

	return 0;

}
