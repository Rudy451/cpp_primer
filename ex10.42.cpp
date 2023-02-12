#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using std::cout; using std::endl; using std::string; using std::list; using std::bind; using namespace std::placeholders; using std::find_if;

list<string> str_lst;

void str_to_lst(const string story, list<string> &str_lst){

	string temp;

        for(size_t i = 0; i < story.size(); ++i){
                if(story[i] == ' '){
                        str_lst.push_back(temp);
                        temp.clear();
                } else {
                        temp += story[i];
                }
        }

        str_lst.push_back(temp);
        temp.clear();


}
bool string_ct(const string word, string::size_type sz){
	return word.size() <= sz;
}

int main(){

	string words = "the big players win the big games";
	str_to_lst(words, str_lst);
	str_lst.sort();
	str_lst.unique();
	for_each(str_lst.begin(), str_lst.end(), [](const string &word){cout << word << endl;});
}
