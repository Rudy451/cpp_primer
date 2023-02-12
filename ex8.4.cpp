#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ex8.4.txt"

using std::cin; using std::cout; using std::endl; using std::vector; using std::string; using std::fstream; 
using std::ifstream; using std::ofstream; using std::getline;

vector<string> ex_vec;

void ex_vec_fill(){

	string temp;
	ifstream ex84_ifile;
	ex84_ifile.open("ex8.4.txt");
	while(getline(ex84_ifile, temp)){
		ex_vec.push_back(temp);
	}
	ex84_ifile.close();
}

int main(){

	ofstream ex84_ofile;
	ex84_ofile.open("ex8.4.txt");
	ex84_ofile << "The First Line\n";
	ex84_ofile << "The Second Line\n";
	ex84_ofile << "The Third Line\n";
	ex84_ofile.close();

	ex_vec_fill();
	for(int i = 0; i < ex_vec.size(); ++i){
		cout << ex_vec[i] << endl;
	}

	return 0;

}
