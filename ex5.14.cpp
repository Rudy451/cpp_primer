#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstddef>

using std::cin; using std::cout; using std::string; using std::istringstream; using std::map; using std::pair; using std::max_element; using std::endl;


int main()
{
	string sentence;
	getline(cin, sentence);
	map<string, int> word_list;

	istringstream iss(sentence);
	string word;

	while(iss >> word){
		if(word_list.empty()){
			word_list.insert(word_list.begin(), pair<string, int>(word, 1));
		} else {
			for(auto i = word_list.begin(); i != word_list.end(); ++i){
				if(word != i->first){
					word_list.insert(i, pair<string, int>(word, 0));
				} else{
					++(i->second);
				}
			}
		}
	}


	auto it = word_list.begin();
	string key_word = it->first;
	int max_count = it->second;

	for(auto its = word_list.begin(); its != word_list.end(); ++its){
		if(its->second > it->second){
			key_word = its->first;
			max_count = its->second;
		} 
	}

	max_count > 1 ? cout << key_word << ": " << max_count << endl : cout << "No duplicates" << endl;
	

}


// Second approach

//	for(int i = 0; i < sentence.size(); ++i){
//		int count = 1;
//		for(int j = i + 1; j < sentence.size(); ++j){
//			if(sentence[i] == "NULL" || sentence[j] == "NULL"){
//				break;
//			} else if(sentence[i] == sentence[j]){
//				++count;
//				sentence[j] = "NULL";
//			}
//		}
//
///		if(sentence[i] != "NULL"){cout << sentence[i] << " count: " << count << endl;}
//		
//	}



