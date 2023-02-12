#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;

void first_program(string demo, string target, bool alpha){

	string::size_type pos = 0;

	if(alpha){
		for(auto &i : demo){
			i = tolower(i);
		}
	}

	while((pos = demo.find_first_of(target, pos)) != string::npos){
		cout << demo[pos] << ", ";
		++pos;
	} 
		
	cout << endl;

}


void second_program(string demo, string target, bool alpha){

	string::size_type pos = 0;

	if(alpha){
		for(auto &i : demo){
			i = tolower(i);
		}
	}

	while((pos = demo.find_first_not_of(target, pos)) != string::npos){
		cout << demo[pos] << ", ";
		++pos;
	} 
		
	cout << endl;

}

void second_program(string demo);

int main(){

	string demo = "ab2c3d7R4E6";
	string number_list = "0123456789";
	string string_list = "abcdefghijklmnopqrstuvwxyz";

	first_program(demo, number_list, false);
	first_program(demo, string_list, true);

	second_program(demo, number_list, false);
	second_program(demo, string_list, true);

}
