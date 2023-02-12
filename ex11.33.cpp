#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <istream>
#include <fstream>
#include <sstream>

using std::cout; using std::endl; using std::map; using std::string; using std::vector; using std::istream; using std::ifstream; using std::istringstream;

void map_and_trans(istream &word_trans, istream &text_msg){

	int text_count;
	string text_line, key, tmp_value, value;
	map<string, string> text_trans;

	while(getline(word_trans, text_line)){
		istringstream map_build(text_line);
		map_build >> key;
		while(map_build >> tmp_value){
			if(text_count > 0){
				value += " ";
			}
			value += tmp_value;
			++text_count;
		}
		text_trans[key] = value;
		tmp_value.clear();
		value.clear();
		text_count = 0;
	}
	key.clear();
	text_line.clear();

	while(getline(text_msg, text_line)){
		istringstream txt_msg(text_line);
		while(txt_msg >> key){
			if(text_trans.find(key) != text_trans.end()){
				cout << text_trans[key] << " ";
			} else {
				cout << key << " ";
			}
		}
		cout << endl;
	}

}

int main(int argc, char *argv[]){
	
	ifstream ex(argv[1]);
	ifstream ex2(argv[2]);
	map_and_trans(ex, ex2);
}
