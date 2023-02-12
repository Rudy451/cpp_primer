#include <iostream>
#include <list>
#include <initializer_list>
#include <memory>
#include <string>
#include <algorithm>
#include<vector>

using namespace std;

template<typename T> class StrBlobPtr;

template<typename T> class StrBlob{

friend class StrBlobPtr<T>;

public:

	StrBlob() = default;
	StrBlob(list<T> il): data(make_shared<list<T>>(il)) {}
	StrBlob(StrBlobPtr<T> start, StrBlobPtr<T> last);
	typedef typename list<T>::size_type sz;

	StrBlobPtr<T> beg();
	StrBlobPtr<T> end();
	sz size() const {return data->size();}
	bool empty() const {return data->empty();}
	void action(T req, T& val);
	void action(T req, T&& val);
	T index(int spot);
private:
	shared_ptr<list<T>> data;
	void check(size_t i, const int &msg) const;

};

template<typename T> class StrBlobPtr{
	
friend class StrBlob<T>;
		
public:
        StrBlobPtr() = default;
        StrBlobPtr(StrBlob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) {}
        T &check_and_do(size_t i, const T &cmd);
private:
        weak_ptr<list<T>> wptr;
        size_t curr = 0;
};

template<typename T> StrBlob<T>::StrBlob(StrBlobPtr<T> start, StrBlobPtr<T> last){

	list<string> temp;

	for(auto i = start.curr; i != last.curr;++i){
		temp.push_back(start.check_and_do(i, "I"));
		start.curr = 0;
	}

	this->data = make_shared<list<T>>(temp);
}

template<typename T> T StrBlob<T>::index(int spot){

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

template <typename T> void StrBlob<T>::action(T req, T& val){

	cout << "LValue" << endl;

	if(req == "add"){
		data->push_back(val);
	} else if(req == "sub"){
		data->pop_back();
	}
}


template <typename T> void StrBlob<T>::action(T req, T&& val){

	cout << "RValue" << endl;

	if(req == "add"){
		data->push_back(val);
	} else if(req == "sub"){
		data->pop_back();
	}
}

template<typename T> StrBlobPtr<T> StrBlob<T>::beg(){
	return StrBlobPtr<T>(*this);
}

template<typename T> StrBlobPtr<T> StrBlob<T>::end(){
	return StrBlobPtr<T>(*this, data->size());
}

template<typename T> T &StrBlobPtr<T>::check_and_do(size_t i, const T &cmd = "D"){

	auto status = wptr.lock();

	if(!status){
		throw runtime_error("unbound StrBlobPtr");
	} 

	if(i >= status->size()){
		throw out_of_range("Index Exceeds Given Size");
	}

	curr = i;
	typename list<T>::iterator it = status->begin();

	advance(it, curr);
	
	return *it;

}

int main(){

	StrBlob<string> ex({"One", "Hi", "Three"});
	StrBlob<string> ex2(ex.beg(), ex.end());
	ex2.action("add", "Four");
	cout << ex2.index(2) << endl;
}
