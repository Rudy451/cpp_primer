#include <iostream>
#include <list>
#include <initializer_list>
#include <memory>
#include <string>
#include <algorithm>

using std::cout; using std::endl; using std::list; using std::string; using std::shared_ptr; using std::make_shared; using std::weak_ptr; using std::runtime_error; using std::out_of_range; using std::size_t; using std::advance;

class ConstStrBlobPtr;

class StrBlob{

friend class ConstStrBlobPtr;

public:
	typedef list<int>::size_type size_tp;
	StrBlob() = default;
	StrBlob(list<int> il): data(make_shared<list<int>>(il)) {}
	ConstStrBlobPtr beg() const;
	ConstStrBlobPtr end() const;
	size_tp size() const {return data->size();}
	bool empty() const {return data->empty();}
	int& action(string req, size_tp i);
	void index(string req, size_tp i = 0, int val = 0);
private:
	shared_ptr<list<int>> data;
	void check(size_tp i, const int &msg) const;

};

class ConstStrBlobPtr{
	
friend class StrBlob;
		
public:
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
        int &check_and_do(size_t i, const string &cmd);
private:
        weak_ptr<list<int>> wptr;
        size_t curr = 0;
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

ConstStrBlobPtr StrBlob::beg() const{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const{
	return ConstStrBlobPtr(*this, data->size());
}

int &ConstStrBlobPtr::check_and_do(size_t i, const string &cmd = "D"){

	auto status = wptr.lock();

	if(!status){
		throw runtime_error("unbound StrBlobPtr");
	} 

	if(i >= status->size()){
		throw out_of_range("Index Exceeds Given Size");
	}

	curr = i;
	list<int>::iterator it = status->begin();
	advance(it, curr);

  	if(cmd[0] == toupper('i')){
		return ++*it;
	} 
	
	return *it;

}
