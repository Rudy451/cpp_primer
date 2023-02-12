#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
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

	//void print(ostream &out);
	
};

void TextQuery::page_build(ifstream &input, vector<string> &page){

	string line, main_line;

	while(getline(input, line)){
		if(line.find(".") < 184467){
			if(!main_line.empty()){
				main_line += line;
				line = main_line;
				main_line.clear();
			}
			page.push_back(line);
		} else {
			main_line += line + " ";
		}
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

void print(ostream &out, QueryResult q){

	out << q.keyword << " occurs " << q.word_count << " times" << endl;
	int j = 0;

	for(auto i = q.line_numbers.begin(); i != q.line_numbers.end(); ++i){
		out << "(line " << *i << ") " << q.text[j++] << endl;
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
public:
	virtual ~Query_base() = default;
private:
	virtual string rep() const = 0;
	virtual QueryResult eval(TextQuery& t) = 0;

};

class WordQuery;

class Query {

	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string &s);
	string rep() const {return q->rep();}
	QueryResult eval(TextQuery& t) const{return q->eval(t);}
private:
	Query(Query_base *query): q(query) {}
	shared_ptr<Query_base> q;
	
};

class WordQuery: public Query_base {

	friend class Query;
	WordQuery(const string &s): query_word(s) {}
	QueryResult eval(TextQuery& t){return t.query(query_word, ex);}
	string rep() const {return query_word;}
	string query_word;
	QueryResult ex;

};

inline Query::Query(const string &s): q(new WordQuery(s)) {}

class NotQuery: public Query_base {

	friend Query operator~(const Query&);
	NotQuery(const Query &q): query(q) {}
	string rep() const {return "~(" + query.rep(); + ")";}
	QueryResult eval(TextQuery& text);
	Query query;

};

QueryResult NotQuery::eval(TextQuery& text){
	
	auto result = query.eval(text);
	QueryResult Temp;
	Temp = text.query(rep(), Temp);
	return Temp;

}

inline Query operator~(const Query &operand){return new NotQuery(operand);}

class BinaryQuery: public Query_base {

protected:
	BinaryQuery(const Query &l, const Query &r, string s): lhs(l), rhs(r), opSym(s) {}
	string rep() const {return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";}
	Query lhs, rhs;
	string opSym;
};

class AndQuery: public BinaryQuery{

	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right): BinaryQuery(left, right, "&") {}
	QueryResult eval(TextQuery& text);
	QueryResult Temp;

};

QueryResult AndQuery::eval(TextQuery& text){

	auto left = lhs.eval(text);
	auto right = rhs.eval(text);
	set<int> ret_lines;
	set_intersection(left.line_numbers.begin(), left.line_numbers.end(), right.line_numbers.begin(), right.line_numbers.end(), inserter(ret_lines, ret_lines.begin()));
	set<string> left_side(left.text.begin(), left.text.end());
	set<string> right_side(right.text.begin(), right.text.end());
	set<string> word_collide;
	set_intersection(left_side.begin(), left_side.end(), right_side.begin(), right_side.end(), inserter(word_collide, word_collide.begin()));
	Temp = text.query(rep(), Temp);
	Temp.line_numbers = ret_lines;
	Temp.text = vector<string>(word_collide.begin(), word_collide.end());
	Temp.word_count = word_collide.size();
	return Temp;

}

inline Query operator&(const Query& lhs, const Query& rhs){return new AndQuery(lhs, rhs);}

class OrQuery : public BinaryQuery{

	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right): BinaryQuery(left, right, "|") {}
	QueryResult eval(TextQuery& text);
	QueryResult Temp;

};

QueryResult OrQuery::eval(TextQuery& text){

	auto left = lhs.eval(text);
	auto right = rhs.eval(text);
	auto ret_lines = set<int>(left.line_numbers.begin(), left.line_numbers.end());
	ret_lines.insert(right.line_numbers.begin(), right.line_numbers.end());
	auto text_print = vector<string>(left.text.begin(), left.text.end());
	text_print.insert(text_print.end(), right.text.begin(), right.text.end());
	auto it = unique(text_print.begin(), text_print.end());
	text_print.resize(distance(text_print.begin(), it));
	Temp = text.query(rep(), Temp);
	Temp.line_numbers = ret_lines;
	Temp.text = text_print;
	Temp.word_count = ret_lines.size();
	return Temp;

}

inline Query operator|(const Query& lhs, const Query& rhs){return new OrQuery(lhs, rhs);}

int main(int argc, char *argv[]){

	ifstream i_file(argv[1]);
//	runQueries(i_file);
	
	TextQuery tq(i_file);
	tq.page_build(tq.i_file, tq.page);
	// Fix binary operations
	auto q = Query("Daddy") & Query("fiery");
	print(cout, q.eval(tq));

	// Third Example
//	OrQuery c = Query("fiery") & Query("bird");	

}

