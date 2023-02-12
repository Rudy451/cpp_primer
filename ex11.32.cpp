#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; using std::endl; using std::map; using std::multimap; using std::string; using std::vector;

void mmap_print(multimap<string, string> &mm){
	
	vector<string> titles;

	for(auto pos = mm.begin(); pos != mm.end(); ++pos){
		string name = pos->first;
		vector<string> titles;
		for(auto sub_pos = mm.equal_range(pos->first); sub_pos.first != sub_pos.second; ++sub_pos.first){
			if((sub_pos.first == mm.lower_bound(pos->first)) || ((sub_pos.first->second)[0] < titles[0][0])){
				titles.emplace(titles.begin(), sub_pos.first->second);
			} else {
				titles.push_back(sub_pos.first->second);
			}
		}
	
		for(auto i = titles.begin(); i != titles.end(); ++i){
			cout << name << ": " << *i << endl;
			if(i != titles.begin()){
				++pos;
			}
		}

		titles.erase(titles.begin(), titles.end());
	}

}

int main(){

	multimap<string, string> authors = {
					    {"Orwell", "Animal Farm"},
					    {"Fitzgerald", "The Great Gatsby"},
					    {"Miller", "The Crucible"},
					    {"Orwell", "1984"},
					    {"Miller", "Death of a Salesman"}};

	mmap_print(authors);
	//cout << std::distance(authors.begin(), std::max_element(authors.begin(), authors.end())) << endl;

}
