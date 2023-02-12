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

class StrBlobPtr2;

class StrBlobPtr{
	
friend class StrBlob;
friend class StrBlob2;
		
public:
        StrBlobPtr() = default;
        StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
        string &check_and_do(size_t i, const string &cmd) const;
	StrBlobPtr2 beg();
	StrBlobPtr2 end();
	StrBlobPtr& operator++();
	StrBlobPtr operator++(int);
	StrBlobPtr& operator--();
	StrBlobPtr operator--(int);
	StrBlobPtr &operator+(const StrBlobPtr &other);
	StrBlobPtr &operator-(const StrBlobPtr &other);
	string &operator*() const;
	string *operator->() const;
	bool wptr_compare(const StrBlobPtr &Other) const;
	size_t ptr_size() const {return curr;}
	string &operator[](const int &num);
	const string &operator[](const int &num) const; 
private:
        weak_ptr<list<string>> wptr;
        mutable size_t curr = 0;
};

class StrBlobPtr2{
	
friend class StrBlobPtr;
		
public:
	StrBlobPtr2() = default;
	StrBlobPtr2(StrBlobPtr &a): strblobptr(a.operator->()){}
	string* operator->() const {return strblobptr;}
private:
	string* strblobptr;

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
	return StrBlobPtr(*this);
}

string &StrBlobPtr::check_and_do(size_t i, const string &cmd = "D") const{

	auto status = wptr.lock();

	if(!status){
		throw runtime_error("unbound StrBlobPtr");
	} 

	if(i >= status->size()){
		throw out_of_range("Index Out of Range");
	}
	
	curr = i;
	list<string>::iterator it = status->begin();
	advance(it, curr);

  	if(cmd[0] == toupper('i')){
		++it;
	} 
	
	return *it;

}

bool StrBlobPtr::wptr_compare(const StrBlobPtr &Other) const {

	auto p1 = this->wptr.lock();
	auto p2 = Other.wptr.lock();
	return *(p1) == *(p2);

}

string &StrBlobPtr::operator[](const int &num){

	auto temp = this->wptr.lock()->begin();
	advance(temp, num);
	return *temp;

}

const string &StrBlobPtr::operator[](const int &num) const {

	auto temp = this->wptr.lock()->begin();
	advance(temp, num);
	return *(temp);
}

StrBlobPtr& StrBlobPtr::operator++(){

	this->check_and_do(this->curr + 1, "i");
	return *this;

}

StrBlobPtr StrBlobPtr::operator++(int){

	auto temp = *this;
	this->check_and_do(this->curr + 1, "i");
	return temp;
	

}

StrBlobPtr& StrBlobPtr::operator--(){

	this->check_and_do(curr - 1, "i");
	return *this;

}

StrBlobPtr StrBlobPtr::operator--(int){

	auto temp = *this;
	this->check_and_do(curr - 1, "i");
	return temp;	

}
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(StrBlobPtr &lhs, StrBlobPtr &rhs);

StrBlobPtr& StrBlobPtr::operator+(const StrBlobPtr &other){

	if(this->wptr.lock() == other.wptr.lock()){
		this->check_and_do(this->curr + other.curr, "i");
	}
	return *this;

}

StrBlobPtr& StrBlobPtr::operator-(const StrBlobPtr &other){

	if(this->wptr.lock() == other.wptr.lock()){
		this->check_and_do(this->curr - other.curr, "i");
	}
	return *this;

}

string &StrBlobPtr::operator*() const{

        return check_and_do(curr);

}

string *StrBlobPtr::operator->() const {

	return & this->operator*();

}

/*string *StrBloVbPtr2::operator->() const {

	return & this->operator*();

}
*/
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs){

	return((lhs.ptr_size() == rhs.ptr_size()) && lhs.wptr_compare(rhs));

}

bool operator!=(StrBlobPtr &lhs, StrBlobPtr &rhs){

	return !(lhs == rhs);	

}

int main(){

	StrBlob first({"My", "Name", "is"});
	StrBlob second({"My", "Name", "is"});
	StrBlobPtr beg(first);
	StrBlobPtr end(first, first.size());
	end.check_and_do(first.size() - 1);
	StrBlobPtr beg2(beg);
	cout << *(beg.operator->()) << endl;
}
