#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout; using std::endl; using std::vector; using std::string;

void string_print(vector<string> str_vec){
	
	for(size_t i = 0; i < str_vec.size(); ++i){
		cout << str_vec[i] << " ";
	}
	
	cout << endl;

}

void string_to_vec(vector<string> &str_vec, string story){

	string temp;

	for(size_t i = 0; i < story.size(); ++i){
		if(story[i] == ' '){
			str_vec.push_back(temp);
			temp.clear();
		} else {
			temp += story[i];
		}
	}

	str_vec.push_back(temp);
	temp.clear();
	string_print(str_vec);
	sort(str_vec.begin(), str_vec.end());
	string_print(str_vec);
	auto str_end = unique(str_vec.begin(), str_vec.end());
	str_vec.erase(str_end, str_vec.end());
	string_print(str_vec);
}

int main(){

	string story = "the best player is on the best team";
	vector<string> str_vec;
	string_to_vec(str_vec, story);

	return 0;

}
