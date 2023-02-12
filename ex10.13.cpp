#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout; using std::endl; using std::vector; using std::string;

bool isLTFive(const string s){

	return s.size() >= 5;

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

	auto bound = partition(str_vec.begin(), str_vec.end(), isLTFive);
	auto start = str_vec.begin();

	while(start != bound){
		cout << *start << endl;
		++start;
	}

}

int main(){

	string story = "The New England Patiots have won five world championships";
	vector<string> str_vec;
	string_to_vec(str_vec, story);

	return 0;

}
