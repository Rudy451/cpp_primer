#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using std::cin; using std::cout; using std::endl; using std::string; using std::vector; using std::ifstream; using std::stringstream; 

vector<string> word_list;

void file_to_vec(ifstream &ex, vector<string> &word_list){

	string word_line;
	
	while(getline(ex, word_line)){
		word_list.push_back(word_line);
	}
}

void vec_to_sstrm(vector<string> word_list){

	string word;

	for(int i = 0; i < word_list.size(); ++i){
		stringstream ex(word_list[i]);
		while(ex >> word){
			cout << word << endl;
		}
	}

}

int main(int argc, char *argv[]){

	ifstream ex(argv[1]);

	file_to_vec(ex, word_list);
	vec_to_sstrm(word_list);

}
