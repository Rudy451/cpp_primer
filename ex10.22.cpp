#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cout; using std::endl; using std::string; using std::vector; using std::bind; using namespace std::placeholders;

vector<string> str_vec;

void str_to_vec(const string story, vector<string> &str_vec){

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
bool string_ct(const string word, string::size_type sz){
	return word.size() >= sz;
}

int main(){

	string words = "The Patriots are the best professional franchise in sports";
	string::size_type sz = 6;
	str_to_vec(words, str_vec);
	auto word_ct = count_if(str_vec.begin(), str_vec.end(), bind(string_ct, _1, sz)); 	
	cout << word_ct << endl;
}
