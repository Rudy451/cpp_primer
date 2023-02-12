#include <iostream>
#include <list>
#include <initializer_list>
#include <memory>
#include <string>
#include <algorithm>

using std::cout; using std::endl; using std::list; using std::string; using std::shared_ptr; using std::make_shared; using std::weak_ptr; using std::runtime_error; using std::out_of_range; using std::size_t; using std::advance;

class StrBlobPtr;

class StrBlob{

friend class StrBlobPtr;

public:
	typedef list<string>::size_type size_tp;

	StrBlob() = default;
	StrBlob(list<string> il): data(make_shared<list<string>>(il)) {}

	StrBlobPtr beg();
	StrBlobPtr end();
	size_tp size() const {return data->size();}
	bool empty() const {return data->empty();}
	void action(string req, string val);
	string index(int spot);
private:
	shared_ptr<list<string>> data;
	void check(size_tp i, const int &msg) const;

};

class StrBlobPtr{
	
friend class StrBlob;
		
public:
        StrBlobPtr() = default;
        StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
        string &check_and_do(size_t i, const string &cmd);
private:
        weak_ptr<list<string>> wptr;
        size_t curr = 0;
};

string StrBlob::index(int spot){

	if(spot >= data->size()){
		throw out_of_range(spot + " on empty StrBlob");
	} else if(spot == 0){
		return data->front();
	} else if(spot == (data->size()-1)){
		return data->back();
	} else {
		auto temp = data->begin();
		advance(temp, spot);
		return *temp;
	}
}

void StrBlob::action(string req, string val=""){

	if(req == "add"){
		data->push_back(val);
	} else if(req == "sub"){
		data->pop_back();
	}
}

StrBlobPtr StrBlob::beg(){
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
	return StrBlobPtr(*this, data->size());
}

string &StrBlobPtr::check_and_do(size_t i, const string &cmd = "D"){

	auto status = wptr.lock();

	if(!status){
		throw runtime_error("unbound StrBlobPtr");
	} 

	if(i >= status->size()){
		throw out_of_range("Index Exceeds Given Size");
	}

	curr = i;
	list<string>::iterator it = status->begin();
	advance(it, curr);

  	if(cmd[0] == toupper('i')){
		++it;
	} 
	
	return *it;

}
