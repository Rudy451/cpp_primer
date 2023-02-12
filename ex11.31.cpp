#include <iostream>
#include <map>
#include <string>

using std::cout; using std::endl; using std::multimap; using std::string; using std::pair;

void mmap_chg(multimap<string, string> &mm, string key_tgt){

	multimap<string, string>::iterator start = mm.find(key_tgt);
	if(start != mm.end()){mm.erase(key_tgt);}
	  

}

int main(){

	multimap<string, string> authors = {{"Fitzgerald", "The Great Gatsby"},
					    {"Miller", "The Crucible"},
					    {"Miller", "Death of a Salesman"},	
					    {"Orwell", "Animal Farm"},
					    {"Orwell", "1984"}};

	mmap_chg(authors, "Orwell");
	mmap_chg(authors, "Miller");
	mmap_chg(authors, "Huxley");
	cout << authors.size() << endl;


}
