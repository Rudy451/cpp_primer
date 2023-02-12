#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class comp_obj{
public:
	// Constructor
	comp_obj(const string &what): comp(what) {}

	// Function
	bool operator()(const string &orig) const {return (orig == comp);}
private:
	string comp;
};

int main(){

	vector<string> sentence = {"the", "Patriots", "are", "the", "Champions"};
	replace_if(sentence.begin(), sentence.end(), comp_obj("the"), "The");
	
	for(auto i = 0; i < sentence.size(); ++i){
		cout << sentence[i] << " ";
	}
	cout << endl;

}

