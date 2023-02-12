#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout; using std::endl; using std::vector; using std::string; using std::partition;

void string_to_vec(vector<string> &str_vec, string story, vector<string>::size_type sz){

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
	sort(str_vec.begin(), str_vec.end());
	auto str_end = unique(str_vec.begin(), str_vec.end());
	str_vec.erase(str_end, str_vec.end());
	stable_sort(str_vec.begin(), str_vec.end(), [](const string &first, const string &second){return first.size() < second.size();});
	auto word_req = partition(str_vec.begin(), str_vec.end(), [sz](const string &s1){return s1.size() >= sz;});
	for_each(str_vec.begin(), word_req, [](const string &s){cout << s << " ";});
	cout << endl;
}

int main(){

	string story = "the best player is on the best team";
	vector<string> str_vec;
	string_to_vec(str_vec, story, 5);

	return 0;

}
