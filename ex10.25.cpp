#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

using std::cout; using std::endl; using std::string; using std::vector; using std::bind; using namespace std::placeholders; using std::find_if;

vector<string> str_vec;
string::size_type sz = 4;

bool string_ct(const string word, string::size_type sz){
	return word.size() <= sz;
}


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

	sort(str_vec.begin(), str_vec.end());
	auto str_end = unique(str_vec.begin(), str_vec.end());
	str_vec.erase(str_end, str_vec.end());
        stable_sort(str_vec.begin(), str_vec.end(), [](const string &first, const string &second){return first.size() < second.size();});
	auto word_req = partition(str_vec.begin(), str_vec.end(), bind(string_ct, _1, sz));
	for_each(str_vec.begin(), word_req, [](const string &s){cout << s << " ";});
	cout << endl;
}

int main(){

	str_to_vec("The 49ers have won five Super Bowls", str_vec);

}
