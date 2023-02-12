#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::string; using std::vector; using std::pair;

int main(){

	vector<string> sent = {"Mary", "had", "a", "little", "lamb"};
	vector<int> num = {1, 2, 3, 4, 5};

	vector<pair<string, int>> project_vec;	

	/* First Way	
	for(int i = 0; i < num.size(); ++i){
		project_vec.emplace_back(make_pair(sent[i], num[i]));
		cout << project_vec[i].first << " " << project_vec[i].second << endl;
	}*/

	/* Second Way
	for(int i = 0; i < num.size(); ++i){
		project_vec.emplace_back(pair<string, int> (sent[i], num[i]));
		cout << project_vec[i].first << " " << project_vec[i].second << endl;
	}*/

	/* Third Way
	for(int i = 0; i < num.size(); ++i){
		project_vec.emplace_back(sent[i], num[i]);
		cout << project_vec[i].first << " " << project_vec[i].second << endl;
	}*/
	

	
}	
