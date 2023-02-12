#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using std::cin; using std::cout; using std::endl; using std::vector; using std::string; using std::istringstream; using std::istream; using std::ifstream;

struct PersonInfo{
	string name;
	vector<string> phones;
};

void PersonInfoFtn(istream &input, vector<PersonInfo> &people){

	string word, line;
	istringstream record;

	while(getline(input, line)){
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while(record >> word){
			info.phones.push_back(word);
		}
		people.push_back(info);
		record.clear();
	}

}

int main(int argc, char *argv[]){

	ifstream ex(argv[1]);
	vector<PersonInfo> people;
	PersonInfoFtn(ex, people);

	cout << people[0].name << endl;
	cout << people[1].name << endl;
	cout << people[2].name << endl;
}
