#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using std::cout; using std::endl; using std::vector; using std::string; using std::set; using std::map;

vector<string> str_vec;
map<string, size_t> word_count;

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
}


void word_count_ftn(vector<string> str_vec, map<string, size_t> &word_count){

	set<string> excl_list = {"the", "at", "it", "in", "on"};
	for(auto i = 0; i < str_vec.size(); ++i){
		if(excl_list.find(str_vec[i]) == excl_list.end()){
			++word_count[str_vec[i]];
		}
	}
	
	for(const auto &word : word_count){
		cout << word.first << ": " << word.second << endl;
	}

}

int main(){

	string sent = "The best player on the best team should win most valuable player";
	string_to_vec(str_vec, sent);
	word_count_ftn(str_vec, word_count);	
	

}
