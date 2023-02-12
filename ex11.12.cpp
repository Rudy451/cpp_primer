#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::string; using std::vector; using std::pair;

int main(){

	pair<string, int> project;
	vector<pair<string, int>> project_vec;

	while(cin >> project.first >> project.second){
		project_vec.emplace_back(pair<string, int> {project.first, project.second});
	}

	for(int i = 0; i < project_vec.size(); ++i){
		cout << project_vec[i].first << " " << project_vec[i].second << endl;	
	}	
}	
