#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <sstream>

using namespace std;

struct QueryResult;

struct TextQuery{

	friend QueryResult;

	// Constructor
	TextQuery(ifstream &input): i_file(input) {}

	// String for page
	ifstream &i_file;
	vector<string> page;
	map<string, set<int>> word_search;

	// Build Vector
	void page_build(ifstream &i_file, vector<string> &pg);

	// Query function
	QueryResult query(string s, QueryResult spot);

	// Indexing
	set<int>::iterator begin(string s, QueryResult target);
	set<int>::iterator end(string s, QueryResult target);

};

struct QueryResult{

	string keyword;
	int word_count = 0;
	vector<string> text;
	set<int> line_numbers;

	void print(ostream &out, QueryResult qry);
	
};

void TextQuery::page_build(ifstream &input, vector<string> &page){

	string line;

	}
	
}

QueryResult TextQuery::query(string s, QueryResult spot){

	bool add = true;
	string word;

	for(auto i = 0; i != this->page.size(); ++i){
		stringstream ex(this->page[i]);
		while(ex >> word){
			if(word == s){
				if(add == true){
					this->word_search[s].insert(i+1);	
					spot.text.push_back(page[i]);
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

set<int>::iterator TextQuery::begin(const string s, QueryResult target){

	return this->word_search[s].begin();

}

set<int>::iterator TextQuery::end(const string s, QueryResult target){

	return this->word_search[s].end();

}

void print(ostream &out, QueryResult qry){

	out << qry.keyword << " occurs " << qry.word_count << " times" << endl;
	int j = 0;
	
	for(auto i = qry.line_numbers.begin(); i != qry.line_numbers.end(); ++i){
		out << "(line " << *i << ") " << qry.text[j++] << endl;
	}

}

void runQueries(ifstream &infile){

	TextQuery tq(infile);
	tq.page_build(tq.i_file, tq.page);
	QueryResult qry;
	
	while(true){
		cout << "Enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q"){break;}
		print(cout, tq.query(s, qry));
	}

}

int main(int argc, char *argv[]){

	ifstream i_file(argv[1]);
	runQueries(i_file);

}
