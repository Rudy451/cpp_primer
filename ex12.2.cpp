#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <algorithm>

using std::cout; using std::endl; using std::list; using std::string; using std::shared_ptr; using std::out_of_range;

class StrBlob{

public:
	typedef list<int>::size_type size_tp;
	StrBlob() = default;
	StrBlob(std::initializer_list<int> il);
	size_tp size() const {return data->size();}
	bool empty() const {return data->empty();}
	int& action(string req, size_tp i);
	void index(string req, size_tp i = 0, int val = 0);
private:
	shared_ptr<list<int>> data;
	void check(size_tp i, const int &msg) const;
};
	
int &StrBlob::action(string req, size_tp i){

	if(i >= data->size()){
		throw out_of_range(req + " on empty StrBlob");
	} else if(req == "front"){
		return data->front();
	} else if(req == "back"){
		return data->back();
	}
}

void StrBlob::index(string req, size_tp i, int val){

	if(i > data->size()){
		throw out_of_range(req + " on empty StrBlob");
	} else if(req == "add"){
		data->push_back(val);
	} else if(req == "sub"){
		data->pop_back();
	}
}

int main(){

}
