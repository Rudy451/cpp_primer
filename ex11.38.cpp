#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <istream>
#include <fstream>
#include <sstream>

using std::cout; using std::endl; using std::set; using std::map; using std::unordered_map; using std::string; using std::vector; using std::istream; using std::ifstream; using std::istringstream;

vector<string> str_vec;
unordered_map<string, size_t> word_count;

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

void word_count_ftn(vector<string> str_vec, unordered_map<string, size_t> &word_count){

        set<string> excl_list = {"the", "at", "it", "in", "on"};
        for(auto i = 0; i < str_vec.size(); ++i){
                if(excl_list.find(str_vec[i]) == excl_list.end()){
                        auto ret = word_count.insert({str_vec[i], 1});
                        if(!ret.second){
                                ++ret.first->second;
                        }
                }
        }

        for(const auto &word : word_count){
                cout << word.first << ": " << word.second << endl;
        }

}

void map_and_trans(istream &word_trans, istream &text_msg){

	int text_count;
	string text_line, key, tmp_value, value;
	unordered_map<string, string> text_trans;

	while(getline(word_trans, text_line)){
		istringstream map_build(text_line);
		map_build >> key;
		while(map_build >> tmp_value){
			if(text_count > 0){
				value += " ";
			}
			value += tmp_value;
			++text_count;
		}
		text_trans[key] = value;
		tmp_value.clear();
		value.clear();
		text_count = 0;
	}
	key.clear();
	text_line.clear();

	while(getline(text_msg, text_line)){
		istringstream txt_msg(text_line);
		while(txt_msg >> key){
			if(text_trans.find(key) != text_trans.end()){
				cout << text_trans[key] << " ";
			} else {
				cout << key << " ";
			}
		}
		cout << endl;
	}

}

int main(int argc, char *argv[]){
	
	string sent = "The best player on the best team should win most valuable player";
        string_to_vec(str_vec, sent);
        word_count_ftn(str_vec, word_count);

	ifstream ex(argv[1]);
	ifstream ex2(argv[2]);
	map_and_trans(ex, ex2);
}
