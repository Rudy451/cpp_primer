#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Str_Comp{
public:
	bool operator()(const string &one, const string &two) const {return (one.size() < two.size());}
};

class Size_Comp{
public:
	Size_Comp(vector<string>::size_type max_val): str_val_sz(max_val) {}
	bool operator()(const string &str_val) const {return (str_val.size() >= str_val_sz);}
private:
	vector<string>::size_type str_val_sz;
};

class Print_String{
public:
	Print_String(ostream &wu): os(wu) {}
	void operator()(const string &p_string) const {cout << p_string << " ";}
private:
	ostream &os;
};

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
	stable_sort(str_vec.begin(), str_vec.end(), Str_Comp());
	auto word_req = find_if(str_vec.begin(), str_vec.end(), Size_Comp(sz));
	for_each(word_req, str_vec.end(), Print_String(cout));
	cout << endl;
}

int main(){

	string story = "the best player is on the best team";
	vector<string> str_vec;
	string_to_vec(str_vec, story, 5);

	return 0;

}
