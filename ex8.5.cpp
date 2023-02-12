#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ex8.5.txt"

using std::cin; using std::cout; using std::endl; using std::vector; using std::string; using std::fstream; 
using std::ifstream; using std::ofstream; using std::getline;

vector<string> ex_vec;

void ex_vec_fill(){

	string temp_line, temp_word;
	ifstream ex85_ifile;
	ex85_ifile.open("ex8.5.txt");

	while(getline(ex85_ifile, temp_line)){
		int i = 0;

		while(i < temp_line.size()){
		
			if(temp_line[i] != ' ' && temp_line[i] != '.'){
				temp_word += temp_line[i];		
			} else {
				ex_vec.push_back(temp_word);
				temp_word.clear();
			}
			++i;
		}
	}
		
	ex85_ifile.close();
}

int main(){

	ofstream ex85_ofile;
	ex85_ofile.open("ex8.5.txt");
	ex85_ofile << "The First Line.\n";
	ex85_ofile << "The Second Line.\n";
	ex85_ofile << "The Third Line.\n";
	ex85_ofile.close();

	ex_vec_fill();

	for(int i = 0; i < ex_vec.size(); ++i){
		cout << ex_vec[i] << endl;
	}

	return 0;

}
