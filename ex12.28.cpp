#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

void pull_file(istream &i_file, vector<string> &lines){

	int spot = 0;
	string line;
		
	while(getline(i_file, line)){
		lines.push_back(line);
	}

}


void t_query(vector<string> lines){	

	string word;
	string t_qry;
	bool found = false;

	set<int> numbers;
	map<int, string> line_num;

	
	while(cin >> t_qry){
		int count = 0;
		for(auto i = 0; i < lines.size(); ++i){
			stringstream ss(lines[i]);
			while(ss >> word){
				if(word == t_qry){
					if(found == false){
						numbers.insert(i+1);
						line_num[i+1] = lines[i];
						found = true;
					}
					++count;
				}
			}
			found = false;
		}

		cout << t_qry << " occurs " << count << " times." << endl;
		for(auto i = numbers.begin(); i != numbers.end(); ++i){
			cout << "(line " << *i << ") " << line_num[*i] << endl;
		}
		numbers.clear();
		line_num.clear();
	}

}

int main(int argc, char *argv[]){

	vector<string> lines;

	ifstream i_file(argv[1]);
	pull_file(i_file, lines);
	t_query(lines);
	
}
