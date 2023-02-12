#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <sstream>
#include "ex12.19.h"

using namespace std;

struct QueryResult;

struct TextQuery{

	friend QueryResult;
	friend StrBlob;

	// Constructor
	TextQuery(ifstream &input): i_file(input) {}
	
	// String for page
	ifstream &i_file;
	// vector<string> page;
	StrBlob page;
	map<string, set<int>> word_search;

	// Build Vector
//	void page_build(ifstream &i_file, vector<string> &pg);
	void page_build(ifstream &i_file, StrBlob &page);

	// Query function
	QueryResult query(string s, QueryResult spot);

};

struct QueryResult{

	string keyword;
	int word_count = 0;
	StrBlob text;
	//vector<string> text;
	set<int> line_numbers;

	void print(ostream &out, QueryResult qry);
	
};

void TextQuery::page_build(ifstream &input, StrBlob &page){

	string line;

	while(getline(input, line)){
		page.action("add", line);
	}
	
}

QueryResult TextQuery::query(string s, QueryResult spot){

	bool add = true;
	string word;

	for(auto i = 0; i != this->page.size(); ++i){
		stringstream ex(this->page.index("index", i);
		while(ex >> word){
			if(word == s){
				if(add == true){
					this->word_search[s].insert(i+1);	
					spot.text.index("add", page.data[i]);
					add = false;
				}
				++spot.word_count;
			}
		}
		add = true;
	}

	spot.keyword = s;
	spot.line_numbers = this->word_search[s];

	return spot;

}

void print(ostream &out, QueryResult qry){

	out << qry.keyword << " occurs " << qry.word_count << " times" << endl;
	int j = 0;
	
	for(auto i = qry.line_numbers.begin(); i != qry.line_numbers.end(); ++i){
		out << "(line " << *i << ") " << qry.text.data[j++] << endl;
	}

}

void runQueries(ifstream &infile){

	TextQuery tq(infile);
	tq.page_build(tq.i_file, tq.page);
	QueryResult qry;
	
	do {
		cout << "Enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q"){break;}
		print(cout, tq.query(s, qry));
	} while(true);

}

int main(int argc, char *argv[]){

	ifstream i_file(argv[1]);
	runQueries(i_file);

}
