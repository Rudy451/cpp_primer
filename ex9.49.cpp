#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout; using std::endl; using std::istream; using std::ifstream; using std::string; using std::vector;

string ascender = "bdfhklt";
string descender = "gjpqy";

string sent_display(istream &s_file, string ascender = ascender, string descender = descender){
	
	string temp_line, temp_word, longest_word;
	
	while(getline(s_file, temp_line)){
		auto i = 0;
		while(i < temp_line.size()){
			if(temp_line[i] != ' ' && temp_line[i] != '.'){
				temp_word += temp_line[i];
			} else {
				if((temp_word.find_first_of(ascender) == string::npos) && (temp_word.find_first_of(descender) == string::npos)){
					if(temp_word.length() > longest_word.length()){
						longest_word = temp_word;
					}
				}
				temp_word.clear();
			}
			++i;
		}
		
	}

	return longest_word;
	
}

int main(int argc, char *argv[]){

	ifstream s_file(argv[1]);
	cout << sent_display(s_file) << endl;

}
