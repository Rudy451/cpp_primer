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

	while(getline(input, line)){
		page.push_back(line);
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

set<int>::iterator TextQuery::begin(const string s, QueryResult target){return this->word_search[s].begin();}

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

class Query;

class Query_base {

	friend class Query;
protected:
	virtual ~Query_base() = default;
private:
	virtual string rep() const = 0;

};

class WordQuery;

class Query {

	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string &s);
	string rep() const {return q->rep();}
private:
	Query(shared_ptr<Query_base> query): q(query) {}
	shared_ptr<Query_base> q;

};

class WordQuery: public Query_base {

	friend class Query;
	WordQuery(const string &s): query_word(s) {cout << "Word Query" << endl;}
	string rep() const {cout << "Word Query Rep" << endl; return query_word;}
	string query_word;

};

inline Query::Query(const string &s): q(new WordQuery(s)) {cout << "Query" << endl;}

class NotQuery: public Query_base {

	friend Query operator~(const Query&);
	NotQuery(const Query& q): query(q) {cout << "Not Query" << endl;}
	Query query;	

};

inline Query operator~(const Query &operand){return shared_ptr<Query_base>(new NotQuery(operand));}

class BinaryQuery: public Query_base {

protected:
	BinaryQuery(const Query &l, const Query &r, string s): lhs(l), rhs(r), opSym(s) {cout << "Binary Query" << endl;}
	string rep() const {return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";}
	Query lhs, rhs;
	string opSym;
};

class AndQuery: public BinaryQuery{

	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right): BinaryQuery(left, right, "&") {cout << "And Query" << endl;}

};

inline Query operator&(const Query& lhs, const Query& rhs){return shared_ptr<Query_base>(new AndQuery(lhs, rhs));}

class OrQuery: public BinaryQuery{

	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right): BinaryQuery(left, right, "|") {cout << "Or Query" << endl;}

};

inline Query operator|(const Query& lhs, const Query& rhs){return shared_ptr<Query_base>(new OrQuery(lhs, rhs));}

int main(int argc, char *argv[]){

	ifstream i_file(argv[1]);
	runQueries(i_file);
	
	// First Example
//	BinaryQuery a = Query("fiery") & Query("bird");

	// Second Example
	AndQuery b = Query("fiery") & Query("bird");

	// Third Example
//	OrQuery c = Query("fiery") & Query("bird");	

}

