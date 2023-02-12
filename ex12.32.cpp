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

	friend StrBlob;
	friend QueryResult;

	// Constructor
	TextQuery(ifstream &input): i_file(input), page(new StrBlob({""})){}
	
	// String for page
	ifstream &i_file;
	shared_ptr<StrBlob> page;
	map<string, shared_ptr<set<int>>> word_search;

	// Build Vector
	void page_build(ifstream &i_file, shared_ptr<StrBlob> page);

	// Query function
	QueryResult query(string s);

};

struct QueryResult{

	friend TextQuery;

	QueryResult(TextQuery ex, string s): key_word(s), text(ex.page), line_numbers(ex.word_search[s]){}

	string key_word;
	int word_count = 0;
	shared_ptr<StrBlob> text;
	shared_ptr<set<int>> line_numbers;

	void print(ostream &out, QueryResult qry);
	
};

void TextQuery::page_build(ifstream &input, shared_ptr<StrBlob> page){

	int i = 0;
	string line;

	page->action("sub");
	while(getline(input, line)){
		page->action("add", line);
	}
	
}

QueryResult TextQuery::query(string s){

	int ct = 0;
	string word;

	for(auto i = 0; i < page->size(); ++i){
		stringstream ex(page->index(i));
		while(ex >> word){
			if(word == s){
				if(!this->word_search[s]){
					this->word_search[s].reset(new set<int>);
				}
				this->word_search[s]->insert(i);
				++ct;
			}
		}
	}

	QueryResult spot(*this, s);
	spot.word_count = ct;

	return spot;

}

void print(ostream &out, QueryResult qry){

	out << qry.key_word << " occurs " << qry.word_count << " times" << endl;
	
	if(qry.word_count > 0){
		for(auto i = qry.line_numbers->begin(); i != qry.line_numbers->end(); ++i){
			out << "(line " << ((*i) + 1) << ") " << qry.text->index(*i) << endl;
		}
	}
}

void runQueries(ifstream &infile){

	TextQuery tq(infile);
	tq.page_build(tq.i_file, tq.page);
	for(auto i = 0; i < tq.page->size(); ++i){
		cout << tq.page->index(i) << endl;
	}
	while(true){
		cout << "Enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q"){break;}
		print(cout, tq.query(s));
	}

}

int main(int argc, char *argv[]){

	ifstream i_file(argv[1]);
	runQueries(i_file);

}
